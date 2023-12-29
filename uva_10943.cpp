#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
#define mod 1000000
typedef long long ll;

vector<vector<int>> memo;

ll dp(int n, int k) {
    if (k == 1) return 1;
    if (memo[n][k] != -1) return memo[n][k];

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += dp(n-i, k-1);
    }
    return memo[n][k] = ans%mod;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    memo.assign(105, vector<int>(105, -1));

    while (n != 0 && k != 0) {
        
        cout << dp(n, k) << "\n";
        
        cin >> n >> k;
    }
}