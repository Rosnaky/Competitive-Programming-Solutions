#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;
#define mod ll(1e9+7)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int& a : arr) {
        cin >> a;
    }

    vector<vector<ll>> dp(100001, vector<ll>(101));

    if (arr[0] == 0) {
        for (ll& col : dp[0]) {
            col = 1;
        }
    }
    dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == 0) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] += dp[i-1][j];

                if (j-1 > 0) dp[i][j] += dp[i-1][j-1];
                if (j+1 <= m) dp[i][j] += dp[i-1][j+1];
                dp[i][j] %= mod;
            }
        }
        else {
            dp[i][arr[i]] += dp[i-1][arr[i]];
            if (arr[i] -1 > 0) dp[i][arr[i]] += dp[i-1][arr[i]-1];
            if (arr[i] +1 <= m) dp[i][arr[i]] += dp[i-1][arr[i]+1];
            dp[i][arr[i]] %= mod;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += dp[n-1][i];
        ans %= mod;
    }
    cout << ans;
}