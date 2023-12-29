#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;


int m, c, price[25][25];
int memo[210][25];

int dp(int money, int g) {
    if (money < 0) return -1000000000;
    if (g == c) return m-money;

    if (memo[money][g] != -1) return memo[money][g];

    int ans = 0;
    for (int i = 1; i <= price[g][0]; i++) {
        ans = max(ans, dp(money-price[g][i], g+1));
    }
    return memo[money][g] = ans;
}


void solve() {

    cin >> m >> c;

    memset(memo, -1, sizeof memo);

    for (int i = 0; i < c; i++) {
        int k; cin >> k;
        price[i][0] = k;
        // cout << k << " ";
        for (int j = 1; j <= k; j++) {
            cin >> price[i][j];
            // cout << price[i][j] << " ";
        }
        // cout << endl;
    }


    int ans = dp(m, 0);
    if (ans == 0) cout << "no solution\n";
    else cout << ans << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; while (t--) solve();
}