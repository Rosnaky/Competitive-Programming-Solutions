#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
typedef long long ll;
#define BIG 1e15

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> seen(n+1);
    vector<ll> dist(n+1, BIG);
    dist[1] = 0;
    priority_queue<vector<ll>> queue;
    queue.push({0, 1, 0});

    while (!queue.empty()) {
        ll node = queue.top()[1], paths = queue.top()[2]; queue.pop();
        
        if (seen[node]) continue;
        seen[node] = true;

        for (int b : adj[node]) {
            if (dist[b] > dist[node]) {
                dist[b] = dist[node];
                queue.push({-dist[b], b, paths});
            }
        }
        if (paths == 2) continue;
        for (int i = 1; i <= n; i++) {
            if (i == node) continue;
            if (dist[i] > dist[node]+pow(node-i, 2)) {
                dist[i] = dist[node]+pow(node-i, 2);
                queue.push({-dist[i], i, paths+1});
            }
        }
    }
    // for (int a : dist) cout << a << " ";
    cout << dist[n] << "\n";
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}