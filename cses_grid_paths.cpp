#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define mod int(1e9+7)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    for (vector<int>& row : grid) {
        for (int& col : row) {
            char temp;
            cin >> temp;
            if (temp == '.') col = 0;
            else col = 1;
        }
    }

    if (grid[n-1][n-1] == 1) {
        cout << 0;
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) continue;
            if(i != n-1) dp[i+1][j] = (dp[i+1][j]+dp[i][j])%mod;
            if(j!= n-1) dp[i][j+1] = (dp[i][j+1]+dp[i][j])%mod; 
        } 
    }

    cout << dp[n-1][n-1];
}