#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> farthest(int node, int par, vector<vector<int>>& adj) {
    int distance = 0;
    int farthestNode = node;

    for (int next : adj[node]) {
        if (next == par) continue;
        auto [tempN, tempD] = farthest(next, node, adj);
        if (tempD +1 > distance) {
            farthestNode = tempN;
            distance = tempD+1;
        }
    }

    return {farthestNode, distance};
}

// int dfs(int node, vector<int>& dist, vector<vector<int>>& adj, vector<bool>& seen) {

//     if (seen[node]) return 0;
//     seen[node] = 1;

//     int ans = 0;
//     for (int i : adj[node]) {
//         int t = dfs(i, dist, adj, seen);
//         if (t > ans) {
//             ans = t;
//         }
//     }

//     dist[node] = ans;

//     return ans+1;

// }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> adj(n+1, vector<int>(n+1));

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dist(n+1, -1);

    auto [fathest, diameter] = farthest(1, -0, adj);

    
}