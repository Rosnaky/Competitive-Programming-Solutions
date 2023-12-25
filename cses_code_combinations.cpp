#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<ll> coins(n);

    for (ll& c : coins) {
        cin >> c;
    }

    vector<ll> dp(x+1, 0);
    dp[0] = 1;

    for (int c : coins) {
        for (int i = 1; i <= x; i++) {
            if (i-c < 0) continue;
            dp[i] = (dp[i]+dp[i-c])%(ll(1e9)+7);
        }
    }
    cout << dp[x];
}