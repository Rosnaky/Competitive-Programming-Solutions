#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
#define BIG int(1e9+7)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<vector<vector<int>>> graph(n+1);
    vector<vector<int>> graph1(n+1, vector<int>(n+1));

    for (int i = 0; i < m; i++) {
        int a, b, c, l;
        cin >> a >> b >> c >> l;
        graph[a].push_back({b, c, l});
        graph[b].push_back({a, c, l});
        graph1[a][b] = c; graph1[b][a] = c;
    }

    ll ans = 0; set<pair<int, int>> edges;
    for (int i = 1; i <= n; i++) {
        vector<vector<pair<int, int>>> paths(n+1);
        vector<int> dist(n+1, BIG);
        dist[i] = 0;
        priority_queue<pair<int, pair<int, vector<pair<int, int>>>>> queue;
        queue.push({0, {i, {}}});
        vector<bool> seen(n+1);

        while(!queue.empty()) {
            vector<pair<int, int>> path = queue.top().second.second; int node = queue.top().second.first;
            queue.pop();

            // if (seen[node]) continue;
            // seen[node] = true;

            for (auto u : graph[node]) {
                int b = u[0], c = u[1], l = u[2];

                if (dist[b] > dist[node]+l) {
                    dist[b] = dist[node]+l;
                    vector<pair<int, int>> temp = path;
                    temp.push_back({node, b});
                    paths[b] = temp;
                    queue.push({-dist[b], {b, temp}});
                }
            }
        }

        
        for (auto p : paths) {
            for (pair<int, int> e : p) {
                if (edges.find({e.first, e.second}) != edges.end()) continue;
                edges.insert({e.first, e.second}); edges.insert({e.second, e.first});
                ans += graph1[e.first][e.second];
                cout << e.first << " " << e.second << endl;
            }
        }
    }

    cout << ans;

}