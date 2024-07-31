#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int encrypt[256];

unordered_map<char, char> loses = {
    {'S', 'H'},
    {'H', 'P'},
    {'P', 'S'}
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int n, k; cin >> n >> k;
    vector<char> fj(n);

    for (char& c : fj) cin >> c;

    encrypt['H'] = 0;
    encrypt['P'] = 1;
    encrypt['S'] = 2;

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(3)));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int l = 0; l < 3; l++) {
                dp[i][j][l] = dp[i-1][j][l];
                if (j) {
                    dp[i][j][l] = max(dp[i][j][l], dp[i-1][j-1][(l+1)%3]);
                    dp[i][j][l] = max(dp[i][j][l], dp[i-1][j-1][(l+2)%3]);
                }
                dp[i][j][l] += (encrypt[loses[fj[i]]] == l);

                ans = max(ans, dp[i][j][l]);
            }
        }
    }

    cout << ans;
    
}