#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, target;
    cin >> n >> target;

    vector<int> coins(n);
    for (int& c : coins) {
        cin >> c;
    }

    vector<int> dp(target+1, 1e9);
    dp[0] = 0;

    for (int i = 1; i <= target; i++) {
        for (int c : coins) {
            if (i-c < 0) continue;

            dp[i] = min(dp[i-c]+1, dp[i]);
        }
    }
    if (dp[target] == 1e9) cout << -1;
    else cout << dp[target];
}