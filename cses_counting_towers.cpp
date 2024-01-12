#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;
#define mod ll(1e9+7)

ll dp[1000006][2];
int highest = 2;

void solve() {

    int n; cin >> n;

    for (int i = highest; i <= n; i++) {
        dp[i][0] = (4*dp[i-1][0] + dp[i-1][1])%mod;
        dp[i][1] = (dp[i-1][0]+2*dp[i-1][1])%mod;
    }
    cout << (dp[n][0]+dp[n][1])%mod << "\n";
    highest = max(highest, n);
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    dp[1][0] = 1;
    dp[1][1] = 1;

    int t; cin >> t;
    while (t--) solve();
}