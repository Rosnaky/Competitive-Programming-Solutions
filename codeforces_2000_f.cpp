#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(k+1, 1e9));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        int x = a[i], y = b[i];
        int cost = 0;
        int xy = x+y;
        for (int j = 0; j <= xy; j++) {
            for (int l = 0; l + j <= k; l++) {
                dp[i+1][l+j] = min(dp[i+1][l+j], dp[i][l] + cost);
            }
            if (j < xy) {
                if (x >= y) {
                    x--, cost += y;
                }
                else {
                    y--, cost += x;
                }
            }
        }
    }

    cout << (dp[n][k] == 1e9 ? -1 : dp[n][k]) << '\n';



}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}