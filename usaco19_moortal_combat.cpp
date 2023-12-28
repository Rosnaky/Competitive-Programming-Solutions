#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

typedef long long ll;
#define BIG 1e15


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;

    vector<vector<int>> graph(m, vector<int>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    for (int k = 0; k < m; k++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                int nCost = graph[i][k] + graph[k][j];
                graph[i][j] = min(graph[i][j], nCost);
            }
        }
    }

    vector<vector<ll>> cost(n, vector<ll>(m));

    for (int i = 1; i <= n; i++) {
        int c = s[i-1]-'a';
        for (int j = 0; j < m; j++) {
            cost[i][j] = cost[i-1][j] + graph[c][j];
        }
    }

    vector<vector<ll>> dp(n, vector<ll>(m));
    for (int i = 0; i < 26; i++) {
        dp[0][i] = 0;
    }
    
    for (int i = k; i <= n; i++) {
        ll minCost = BIG;
        for (int j = 0; j < m; j++) {
            minCost = min(minCost, dp[i-k][j]);
        }
        int c = s[i-1]-'a';
        for (int j = 0; j <m; j++) {
            dp[i][j] = min(minCost + cost[i][j] - cost[i-k][j], dp[i-1][j] + graph[c][j]);
        }
    }

    ll ans = BIG;
    for (int i = 0; i < m; i++) {
        ans = min(ans, dp[n][i]);
    }

    cout << ans << "\n";
}