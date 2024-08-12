#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);

    int n, k; cin >> n >> k;

    vector<int> a(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    vector<vector<int>> pref(n + 1, vector<int>(n+1));

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int mx = 0, diff = 0;
            for (int x = i; x <= j; x++) mx = max(mx, a[x]);
            for (int x = i; x <= j; x++) diff += mx - a[x];

            pref[i][j] = diff;
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
    dp[1][0] = 0;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (!j) {
                dp[i][j] = pref[1][i];
                continue;
            }

            for (int x = 1; x < i; x++) {
                dp[i][j] = min(dp[i][j], dp[x][j-1] + pref[x+1][i]);
            }
        }
    }



    cout << dp[n][k] << '\n';
    
}