#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& seen) {
    seen[node] = true;

    for (int a : graph[node]) {
        if (seen[a]) continue;
        dfs(a, graph, seen); 
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    vector<vector<int>> graph1(n+1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph1[b].push_back(a);
    }

    vector<bool> seen(n+1);

    dfs(1, graph, seen);

    for (int i = 2; i <= n; i++) {
        if (!seen[i]) {
            cout << "NO" << "\n";
            cout << 1 << " " << i;
            return 0;
        }
    }

    vector<bool> seen1(n+1);
    dfs(1, graph1, seen1);

    for (int i = 2; i <= n; i++) {
        if (!seen1[i]) {
            cout << "NO" << "\n";
            cout << i << " " << 1;
            return 0;
        }
    }

    cout << "YES";
}