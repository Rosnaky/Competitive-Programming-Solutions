#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);


    int n, m; cin >> n >> m;

    vector<pair<int, int>> edges(m);
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = {u, v};
    }

    
    vector<int> colours(m); // 0 = gray, 1 = blue, 2 = red
    vector<vector<bool>> seen(n+1, vector<bool>(n+1));
    for (int i = 0; i < m; i++) {
        
        auto [u, v] = edges[i];
        if (colours[i] != 0) continue;

        queue<pair<int, bool>> queue;
        queue.push({u, 0});

        vector<bool> visited(n+1);

        while (!queue.empty()) {

            auto [node, c] = queue.front();
            queue.pop();

            if (visited[node]) continue;
            visited[node] = 1;

            

        }
        
    }

    for (int i = 0; i < m; i++) {
        if (colours[i] == 0) cout << "G";
        else if (colours[i] == 1) cout << "B";
        else cout << "R";
    }

    
}