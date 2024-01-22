#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int sz[222222];

void init(int v, vector<vector<int>>& adj) {
    sz[v] = 1;
    for (int u : adj[v]) {
        init(u, adj);
        sz[v] += sz[u];
    }
}


int calc(int node, int ans, vector<vector<int>>& adj) {
    int tot = 0, mx = -1;
    for (int u : adj[node]) {
        tot += sz[u];
        if (mx == -1 || sz[mx] < sz[u]) mx = u;
    } 
    if (tot == 0) return 0;
    if (sz[mx]-ans <= tot - sz[mx]) return (tot-ans)/2;

    int add = tot-sz[mx];
    return add + calc(mx, max(0, ans+add-1), adj);
}


void solve() {
    int n; cin >> n;

    vector<vector<int>> adj(n+1);
    for (int i = 2; i <= n; i++) {
        int a; cin >> a;
        adj[a].push_back(i);
    }

    init(1, adj);
    cout << calc(1, 0, adj) << "\n";

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}