#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


void solve() {

    int n, m; cin >> n >> m;
    int t0, t1, t2; cin >> t0 >> t1 >> t2;

    vector<vector<vector<int>>> adj(n+1);

    for (int i = 0; i < m; i++) {
        int u, v, l1, l2; cin >> u >> v >> l1 >> l2;
        adj[u].push_back({v, l1, l2});
        adj[v].push_back({u, l1, l2});
    }

    priority_queue<pair<int, int>> queue;


    queue.push({t0, n});
    vector<int> dist(n+1, -1e9);
    dist[n] = t0;

    while (!queue.empty()) {

        auto [time, node] = queue.top(); queue.pop();

        if (time < dist[node]) continue;

        for (auto& v : adj[node]) {

            int next = v[0], bus = v[1], walk = v[2];
            int newTime = (time - bus >= t2 || time <= t1) ? time - bus : time - walk;
            if (newTime == time - walk) newTime = max(newTime, t1 - bus);

            if (newTime > dist[next]) {
                
                queue.push({newTime, next});
                dist[next] = newTime;
            }
        }
    }

    
    

    cout << (dist[1] >= 0 ? dist[1] : -1) << '\n';



}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

