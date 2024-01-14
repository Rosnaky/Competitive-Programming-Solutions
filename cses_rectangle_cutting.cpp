#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> dp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    dp = vector<vector<int>>(a+1, vector<int>(b+1, 1e9));

    
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            if (i == j) dp[i][j] = 0;
            else {
                int ans = 1e9;
                for (int k = 1; k < i; k++) {
                    ans = min(ans, dp[i-k][j] + dp[k][j]+1);
                }
                for (int k = 1; k < j; k++) {
                    ans = min(ans, dp[i][j-k] + dp[i][k]+1);
                }
                dp[i][j] = ans;
            }
        }
    }
    cout << dp[a][b];
}