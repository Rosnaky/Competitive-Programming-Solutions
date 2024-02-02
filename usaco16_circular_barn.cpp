#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("cbarn.in", "r", stdin); freopen("cbarn.out", "w", stdout);

    int n; cin >> n;

    vector<int> r(n);

    for (int& i : r) cin >> i;

    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        int temp = 0;

        for (int j = 0; j < n; j++) {
            if (i > j) {
                temp += (n-i+j)*r[j];
            }
            else {
                temp += (j-i)*r[j];
            }
        }

        ans = min(ans, temp);
    }
    cout << ans;
}