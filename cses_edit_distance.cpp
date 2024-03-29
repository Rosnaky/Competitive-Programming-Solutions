#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s1, s2; cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();

    vector<vector<int>> dp (n+1, vector<int>(m+1, 1e9));

    dp[0][0] = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
            if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
            if (i > 0 && j > 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1]+(s1[i-1] != s2[j-1]));
        }
    }
    // for (auto row : dp) {
    //     for (auto col : row) {
    //         cout << col << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n][m];
}