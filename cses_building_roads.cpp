#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> ans;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& seen) {
    if (seen[node]) return;

    seen[node] = true;
    
    for (int n : graph[node]) {
        dfs(n, graph, seen);
    } 
}


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

    vector<bool> seen(n+1, false);

    dfs(1, graph, seen);

    for (int i = 1; i <= n; i++) {
        if (!seen[i]) {
            graph[1].push_back(i);
            graph[i].push_back(1);
            ans.push_back({1, i});
            dfs(i, graph, seen);
        }
    }

    cout << ans.size() << "\n";
    for (pair<int, int>& p : ans) {
        cout << p.first << " " << p.second << "\n";
    }
}