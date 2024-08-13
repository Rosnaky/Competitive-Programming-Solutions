#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);

    int n, x; cin >> n >> x;

    vector<int> weights(n+1);

    for (int i = 1; i <= n; i++) cin >> weights[i];

    vector<vector<int>> dp(n+1, vector<int>(x+1, 1e9));

    for (int i = 0; i <= n; i++) dp[i][weights[i]] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = weights[i]; j <= x; j++) {
            for (int k = 0; k <= x-j; k++) {
                for (int l = 1; l <= i; l++) {
                    dp[i][j] = min(dp[i][j], dp[l][k]);
                    dp[i][j] = min(dp[i][j], dp[i][j-1]);
                }
            }
        }
    }

    cout << dp[n][x];

    

}