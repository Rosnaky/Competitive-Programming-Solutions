#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n;

void dfs(int i, vector<bool>& visited, vector<vector<int>>& adj) {
    if (visited[i]) return;

    visited[i] = true;

    for (int a : adj[i]) {
        if (a == i || visited[a]) continue;
        dfs(a, visited, adj);
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    vector<vector<int>> adj(n+1);

    for (int i = 1; i <= n; i++) {
        int p; cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    int ans = 0;
    vector<bool> visited(n+1);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            ans++;
            dfs(i, visited, adj);
        }
    }
    cout << ans;
}