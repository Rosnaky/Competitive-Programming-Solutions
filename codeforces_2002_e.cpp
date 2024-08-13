#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {

    int n; cin >> n;
    vector<int> a = {0};

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        while (x--) {
            a.push_back(y);
        }
    }

    n = a.size();

    vector<vector<int>> dp(n+1, vector<int>(n+1));

    for (int i = 1; i <= n; i++) {
        dp[i][i] = 1;
    }
    for (int i = 1; i < n; i++) {
        dp[i][i+1] = (a[i] == a[i+1]) ? 2 : 1;
    }

    for (int i = 3; i <= n; i++) {
        for (int j = 0; j <= n-i+1; j++) {

            dp[j][j+i-1] = i;

            

        }
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();

}