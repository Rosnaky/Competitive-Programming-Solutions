#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }


    queue<int> queue;
    vector<int> dist(n+1, INT_MAX);
    vector<int> parent(n+1);
    dist[1] = 0;

    queue.push({1});

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();

        for (int i : graph[node]) {
            if (dist[i] == INT_MAX) {
                dist[i] = dist[node] + 1;
                parent[i] = node;
                queue.push(i);
            }
        }
    }

    if (dist[n] == INT_MAX) cout << "IMPOSSIBLE";
    else {
        cout << dist[n]+1 << '\n';

        vector<int> path = {n};
        while (path[path.size()-1] != 1) path.push_back(parent[path[path.size()-1]]);
        reverse(path.begin(), path.end());
        for (int i : path) cout << i << " ";
    }
}