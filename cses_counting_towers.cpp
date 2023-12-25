#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;
#define mod ll(1e9)+7

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    ll dp[100005][3];
    dp[1][1] = dp[1][2] = 1;

    for (int i = 2; i < 100005; i++) {
        dp[i][1] = ((dp[i-1][1]*4)%mod + dp[i-1][2])%mod;
        dp[i][2] = (dp[i-1][1] + (dp[i-1][2]*2)%mod)%mod;
    }

    while (--t) {
        int n; cin >> n;
        cout << (dp[n][1] + dp[n][2])%mod << "\n";
    }
}