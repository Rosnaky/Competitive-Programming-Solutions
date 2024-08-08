#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


void solve() {
    
    int n; cin >> n;

    vector<int> a(n);
    for (int &i : a) cin >> i;

    if (n <= 3) {
        cout << a[0] << "\n";
        return;
    }

    vector<vector<int>> dp(n, vector<int>(2, 0));

    dp[0][0] = a[0];
    dp[1][0] = a[0]+a[1];

    dp[0][1] = 1e9;
    dp[1][1] = a[0];

    for (int i = 2; i < n; i++) {
        dp[i][0] = min(dp[i-1][0] + a[i], dp[i-1][1]) + a[i];
        dp[i][1] = min(dp[i-1][0], dp[i-2][0]);
    }

    

    cout << min(dp[n-1][0], dp[n-1][1]) << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--) solve();
}