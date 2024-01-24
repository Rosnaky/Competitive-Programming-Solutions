#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


void dfs(int node, vector<vector<int>>& adj, vector<bool>& seen) {
    if (seen[node]) return;
    seen[node] = true;

    for (int a : adj[node]) dfs(a, adj, seen);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("factory.in", "r", stdin); freopen("factory.out", "w", stdout);

    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for (int i = 1; i < n;i++) {
        int a, b; cin >> a >> b;
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        vector<bool> seen(n+1);
        seen[0] = true;
        dfs(i, adj, seen);

        bool good = true;
        for (int a : seen) {
            good = good && a;
            if (!good) break;
        }
        if (good) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}