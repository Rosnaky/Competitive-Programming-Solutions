#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("lazy.in", "r", stdin); freopen("lazy.out", "w", stdout);

    int n, k; cin >> n >> k;
    int prefix[n+1][n+1], a[n+1][n+1];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        prefix[i][0] = 0;
        for (int j = 0; j < n; j++) {
            prefix[i][j+1] = prefix[i][j] + a[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0, l = i;
            int left = j-k+1, right = j+k+1;
            while (l >= 0 && right >= left) {
                sum += prefix[l][min(right, n)] - prefix[l][max(left, 1)-1];
                right--, left++, l--;
            }
            l = i+1, left = j-k+2, right = j+k;

            while (l < n && right >= left) {
                sum += prefix[l][min(right, n)] - prefix[l][max(left, 1)-1];
                right--, left++, l++;
            }
            ans = max(ans, sum);
        }
    }

    cout << ans << '\n';
}