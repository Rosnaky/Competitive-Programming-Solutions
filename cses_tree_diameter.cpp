#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

pair<int, int> dfs(int node, int par, vector<vector<int>>& adj) {
    int distance = 0;
    int farthestNode = node;

    for (int next : adj[node]) {
        if (next == par) continue;
        auto [tempN, tempD] = dfs(next, node, adj);
        if (tempD +1 > distance) {
            farthestNode = tempN;
            distance = tempD+1;
        }
    }

    return {farthestNode, distance};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int node = dfs(1, -1, adj).first;
    
    int ans = dfs(node, -1, adj).second;
    cout << ans;
}