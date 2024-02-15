#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool dfs(int p, int q, vector<vector<bool>>& graph, vector<bool>& seen) {
    // if (seen[p]) return false;
    seen[p] = true;

    if (p == q) return true;

    for (int i = 1; i < graph[p].size(); i++) {
        if (p == i) continue;
        if (graph[p][i] && !seen[i]) {
            if (dfs(i, q, graph, seen)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<vector<bool>> graph(n+1, vector<bool>(n+1));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = true;
    }

    int p, q;
    cin >> p >> q;

    vector<bool> seen(n+1);
    vector<bool> seen1(n+1);
    
    if (dfs(p, q, graph, seen)) {
        cout << "yes";
    }
    else if (dfs(q, p, graph, seen1)) {
        cout << "no";
    }
    else {
        cout << "unknown";
    }
}