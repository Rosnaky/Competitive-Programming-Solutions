#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& ans) {
    if (ans[node]) return;

    int ava = 0;
    sort(adj[node].begin(), adj[node].end());
    for (int a : adj[node]) {
        if (ans[a]) {
            ava |= (1<<(ans[a]-1));
        }
    }

    for (int i = 0; i < 4; i++) {
        if (ava & (1 << i)) {
            continue;
        }
        ans[node] = i+1;
        return;
    }

    for (int a : adj[node]) {
        if (!ans[a]) dfs(a, adj, ans);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> ans(n+1);
    for (int i = 1; i <= n; i++) {
        dfs(i, adj, ans);
    }

    for (int i = 1; i<= n; i++) cout << ans[i];

}