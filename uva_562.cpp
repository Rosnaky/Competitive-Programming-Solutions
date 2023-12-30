#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

int n;
vector<int> coins;
vector<vector<ll>> memo;

ll dp(int i, ll left, ll right) {
    if (i == n) return abs(left-right);
    if (memo[i][left] != -1) return memo[i][left];
    return memo[i][left] = min(dp(i+1, left+coins[i], right), dp(i+1, left, right+coins[i]));
}


void solve() {
    
    cin >> n;
    // memo = vector<ll>(n+1, -1);
    memo.assign(n, vector<ll>(500000, -1));
    coins = {};

    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        coins.push_back(c);
    }

    ll ans = dp(0, 0, 0);

    cout << ans << "\n";
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}