#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
#define BIG int(1e9+7)

void solve(int n, int m) {
    // int n, m;
    // cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    for (int i = 1; i <= n; i++) {
        vector<int> dist(n+1, BIG);
        dist[i] = 0;
        vector<bool> seen(n+1);
        vector<int> par(n+1);

        priority_queue<pair<int, int>> queue;
        queue.push({0, i});

        while (!queue.empty()) {
            int node = queue.top().second;
            queue.pop();

            if (node == i && seen[node]) {
                vector<int> path;
                while (par[node] != node) {
                    path.push_back(node);
                    node = par[node];
                }
                path.push_back(node);
                reverse(path.begin(), path.end());
                for (int c : path) cout << c << " ";
                cout << "\n";
                return;
            }

            // if (seen[node]) continue;
            seen[node] = true;

            for (pair<int, int>& u : graph[node]) {
                int b = u.first, w = u.second;
                if (dist[b] > dist[node]+w) {
                    dist[b] = dist[node]+w;
                    par[b] = node;
                    queue.push({-dist[b], b});
                }
            }
        }
    }

    cout << "No solution.\n";
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int n, m;
    cin >> n >> m;
    while (n != -1 && m != -1) solve(n, m);
}