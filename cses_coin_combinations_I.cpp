#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, target;
    cin >> n >> target;

    vector<ll> coins(n);

    for (ll& c : coins) {
        cin >> c;
    }

    vector<ll> dp(target+1, 0);
    dp[0] = 1;

    for (ll i = 1; i <= target; i++) {
        for (ll c : coins) {
            if (i - c < 0) continue;
            dp[i] += dp[i-c];
        }
        dp[i] %= ll(1e9)+7;
    }
    cout << dp[target];
}