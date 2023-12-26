#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& used, vector<bool>& closed) {
    used[node] = true;

    for (int a : graph[node]) {
        if (!closed[a] && !used[a]) {
            dfs(a, graph, used, closed);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    vector<bool> closed(n+1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        vector<bool> used(n+1);
        int ans = 0;

        for (int u = 1; u <= n; u++) {
            if (!closed[u] && !used[u]) {
                ans++;
                dfs(u, graph, used, closed);

                if (ans > 1) break;
            }
        }

        cout << (ans <= 1 ? "YES" : "NO") << "\n";

        int k;
        cin >> k;
        closed[k] = true;
    }
}