#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;


int m, c, price[25][25];
bool reachable[25][210];

// int dp(int money, int g) {
//     if (money < 0) return -1000000000;
//     if (g == c) return m-money;

//     if (memo[money][g] != -1) return memo[money][g];

//     int ans = 0;
//     for (int i = 1; i <= price[g][0]; i++) {
//         ans = max(ans, dp(money-price[g][i], g+1));
//     }
//     return memo[money][g] = ans;
// }


void solve() {

    cin >> m >> c;

    memset(reachable, false, sizeof reachable);

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

    for (int g = 1; g <= price[0][0]; g++) {
        if (m-price[0][g] >= 0) {
            reachable[0][m-price[0][g]] = true;
        }
    }
    for (int g = 1; g < c; g++) {
        for (int money = 0; money<m; money++) {
            for (int k = 1; k <= price[g][0]; k++) {
                if (money-price[g][k] >= 0) reachable[g][money-price[g][k]] = true;
            }
        }
    }
    int money;
    for (money = 0; money <= m && !reachable[c-1][money]; money++);
    

    if (money == m+1) cout << "no solution\n";
    else cout << m-money << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; while (t--) solve();
}