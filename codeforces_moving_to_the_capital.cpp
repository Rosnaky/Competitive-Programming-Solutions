#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


void solve() {


    int n, m; cin >> n >> m;

    vector<vector<bool>> adj(n+1, vector<bool>(n+1));
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u][v] = 1;
    }


    vector<vector<int>> dp(n+1, vector<int>(2, 1e9));
    vector<int> dist(n+1);
    queue<int> queue; 
    queue.push(1);
    int curr = 0;
    vector<bool> seen(n+1);
    seen[1] = 1;
    dp[1][0] = 0;

    while (!queue.empty()) {
        int x = queue.size();
        curr++;
        while (x--) {
            int node = queue.front(); queue.pop();
            
            for (int next = 1; next <= n; next++) {
                if (!adj[node][next]) continue;
                if (seen[next]) continue;
                seen[next] = 1;
                
                dp[next][0] = curr;
                dist[next] = curr;

                queue.push(next);
            }
        }
    }

    for (int i : dist) cout << i << " ";
    cout << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 1; k <= n; k++) {
                if (adj[k][i]) {
                    if (!j) {
                        if (dist[i] <= dist[k]) continue;
                        else {
                            dp[i][j] = min(dp[i][j], dp[k][j]);
                        }
                    } 
                    else {
                        if (dist[i] <= dist[k]) {
                            dp[i][j] = min(dp[i][j], dp[k][j-1]);
                        }
                        else {
                            dp[i][j] = min(dp[i][j], dp[k][j]);
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dp[i][1] << " ";
    }
    cout << '\n';

    for (int j = 0; j < 2; j++) {
        for (int i = 1; i <= n; i++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;

    while (t--) solve();
}