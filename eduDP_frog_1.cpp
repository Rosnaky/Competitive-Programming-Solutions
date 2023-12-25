#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> rocks(n);

    for (int& r : rocks) {
        cin >> r;
    }

    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    
    for (int i = 0; i < n; i++) {
        dp[i+1] = min(dp[i+1], dp[i] + abs(rocks[i] - rocks[i + 1]));
        if (i+2 < n) {
            dp[i + 2] = min(dp[i + 2], dp[i] + abs(rocks[i] - rocks[i + 2]));
        }
    }

    cout << dp[n-1];
}
