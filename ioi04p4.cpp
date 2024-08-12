#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int w, h; cin >> w >> h;
    int n; cin >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    vector<vector<int>> dp(w+1, vector<int>(h+1));
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= h; j++) {
            dp[i][j] = i*j;
        }
    }

    for (int i = 0; i < n; i++) {
        dp[x[i]][y[i]] = 0;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= h; j++) {
            for (int l = 1; l < i; l++) {
                dp[i][j] = min(dp[i][j], dp[l][j] + dp[i-l][j]);
            }
            for (int l = 1; l < j; l++) {
                dp[i][j] = min(dp[i][j], dp[i][l] + dp[i][j-l]);
            }
        }
    }

    cout << dp[w][h] << '\n';
}