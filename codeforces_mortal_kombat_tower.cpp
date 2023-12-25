#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        
        int n;
        cin >> n;

        vector<int> tower(n);
        for (int& t : tower) {
            cin >> t;
        }

        if (n <= 3) {
            cout << tower[0] << "\n";
            continue;
        }

        vector<vector<int>> dp(n, vector<int>(2, 0));
        if (tower[0] == 1) dp[0][0] = 1;
        else dp[0][0] = 0;
        if(tower[1] == 1) dp[1][0] = 1+dp[0][0];
        else dp[1][0] = dp[0][0];

        dp[0][1] = 1e9;
        dp[1][1] = dp[0][0];

        for (int i = 2; i < n; i++) {
            dp[i][0] = tower[i]+min(dp[i-1][1], tower[i-1]+dp[i-1][0]);
            dp[i][1] = min(dp[i-1][0], dp[i-2][0]);
        }

        cout << min(dp[n-1][0], dp[n-1][1]) << "\n";
    }
}