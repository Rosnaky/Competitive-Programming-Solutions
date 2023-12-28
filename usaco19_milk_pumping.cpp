#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    vector<vector<vector<ll>>> graph(n+1);
    for (int i = 0; i < m; i++) {
        ll a, b, c, f;
        cin >> a >> b >> c >> f;
        graph[a].push_back({b, c, f});
        graph[b].push_back({a, c, f});
    }

    priority_queue<pair<ll, vector<ll>>> queue;
    queue.push({0, {1, 0, int(1e9)}}); // flow / cost, {node, cost, flow}

    vector<ll> distance(n+1);
    vector<bool> seen(n+1);

    while (!queue.empty()) {
        ll node = queue.top().second[0], cost = queue.top().second[1], flow = queue.top().second[2]; queue.pop();

        if (seen[node]) continue;
        seen[node] = true;

        for (auto i : graph[node]) {
            if ((ll)min(flow, i[2])*(1e6)/((cost+i[1])) > distance[i[0]]) {
                distance[i[0]] = (ll)min(flow, i[2])*(1e6)/(cost+i[1]);
                queue.push({-distance[i[0]], {i[0], cost+i[1], min(flow, i[2])}});
            }
        }
    }

    cout << distance[n] << "\n";

}