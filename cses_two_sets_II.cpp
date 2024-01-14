#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
#define mod int(1e9+7);
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int target = n*(n+1)/2;

    if (target % 2 == 1) {
        cout << 0; return 0;
    }

    target /= 2;

    vector<vector<int>> dp(n, vector<int>(target+1, 0));
    dp[0][0] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= target; j++) {
            dp[i][j] = dp[i-1][j];
            int left = j-i;
            if (left >= 0) {
                (dp[i][j] += dp[i-1][left]) %= mod;
            }
        }
    }
    cout << dp[n-1][target];

}