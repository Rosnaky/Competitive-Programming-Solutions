#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

void dfs(vector<vector<pair<int, int>>>& graph, vector<int>& states, int node, bool colour, bool& impossible) {
    // cout << node << " " << colour;
    
    if (impossible) return;

    if (states[node] != 2 && states[node] != colour) {
        impossible = true;
        return;
    }

    if (states[node] == colour) return;

    states[node] = colour;

    for (pair<int, int>& e : graph[node]) {
        int n = e.first, t = e.second;

        if (t == 1) {
            dfs(graph, states, n, colour, impossible);
        }
        else {
            dfs(graph, states, n, !colour, impossible);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n+1);

    for (int i = 0; i < m; i++) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        
        if (c == 'S') {
            graph[a].push_back({b, 1});
            graph[b].push_back({a, 1});
        }
        else {
            graph[a].push_back({b, 2});
            graph[b].push_back({a, 2});
        }
    }

    vector<int> states(n+1, 2);
    int ans = 0;
    bool impossible = false;
    for (int i = 1; i <= n; i++) {
        if (states[i] != 2) continue;
        ans++;
        dfs(graph, states, i, false, impossible);
        if (impossible) break;
    }
    
    if (impossible) cout << 0;
    else {
        cout << 1;
        for (int i = 0; i < ans; i++) {
            cout << 0;
        }
    }
}