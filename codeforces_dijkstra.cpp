#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define BIG 1000000000000000
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    vector<ll> dist(n+1, BIG);
    vector<bool> seen(n+1);
    vector<int> par(n+1);
    priority_queue<pair<ll, int>> queue;
    dist[1] = 0;
    queue.push({0, 1});
    par[1] = 1;

    while (!queue.empty()) {
        int node = queue.top().second; queue.pop();

        if (seen[node]) continue;
        seen[node] = true;

        if (node == n) {
            vector<int> path;
            while (par[node] != node) {path.push_back(node); node = par[node];}
            path.push_back(1);
            reverse(path.begin(), path.end());
            for (int c : path) cout << c << " ";
            return 0;
        }

        for (auto i : graph[node]) {
            if (dist[i.first] > dist[node]+i.second) {
                dist[i.first] = dist[node]+i.second;
                par[i.first] = node;
                queue.push({-dist[i.first], i.first});
            }
        }
    }

    cout << -1;
}