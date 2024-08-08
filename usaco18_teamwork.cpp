#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> cows(n+1);
    for (int i = 1; i <= n; i++) cin >> cows[i];

    vector<int> dp(n+1);
    dp[1] = cows[1];

    for (int i = 2; i <= n; i++) {
        int mx = cows[i];
        for (int j = i; j > 0 && i-j+1 <= k; j--) {
            mx = max(mx, cows[j]);
            dp[i] = max(dp[i], dp[j-1] + mx * (i-j+1));
        }
    }

    cout << dp[n];

    
}