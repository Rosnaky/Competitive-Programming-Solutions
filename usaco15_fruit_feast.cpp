#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5e6+5;
int dp[2][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);

    int t, a, b; cin >> t >> a >> b;
    
    dp[0][0] = true;

    for (int i = 0; i <= t; i++) {
        if (i-a >= 0) dp[0][i] |= dp[0][i-a];
        if (i-b >= 0) dp[0][i] |= dp[0][i-b];
        dp[1][i/2] |= dp[0][i];
    }
    for (int i = 0; i <= t; i++) {
        if (i-a >= 0) dp[1][i] |= dp[1][i-a];
        if (i-b >= 0) dp[1][i] |= dp[1][i-b];
    }
    
    for (int i = t; i >= 0; i--) {
        if (dp[1][i]) {
            cout << i;
            return 0;
        }
    }
}