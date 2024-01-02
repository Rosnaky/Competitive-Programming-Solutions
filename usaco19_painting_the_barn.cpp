#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
#define arrSize 1005

int prefix[arrSize][arrSize];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("paintbarn.in", "r", stdin); freopen("paintbarn.out", "w", stdout);

    int n, k; cin >> n >> k;

    for (int i = 0; i < n; i++) {

        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2; x1++, y1++, x2++, y2++;
        prefix[x1][y1]++;
        prefix[x2][y2]++;
        prefix[x1][y2]--;
        prefix[x2][y1]--;
    }

    int ans = 0;
    for (int i = 1; i < arrSize; i++) {
        for (int j = 1; j < arrSize; j++) {
            prefix[i][j] += prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
            if (prefix[i][j] == k) ans++;
        }
    }
    cout << ans;
}