#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;



int dfs(int node, int par, vector<vector<int>>& adj) {
    
    int ans = adj[node].size()+1;
    for (int a : adj[node]) {
        if (a == par) continue;

        ans = max(ans, dfs(a, node, adj));
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("planting.in", "r", stdin); freopen("planting.out", "w", stdout);

    int n; cin >> n;

    vector<vector<int>> adj(n+1);
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> seen(n+1);
    cout << dfs(1, -1, adj);
}