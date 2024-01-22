#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

void dfs(int node, int par, ll& days, vector<vector<int>>& adj) {
    int curr = 1;
    while (curr < adj[node].size()) curr*=2, days++;

    // cout << node << " " << curr << " "  <<  days << "\n";

    for (int i : adj[node]) {
        if (i == par) continue;
        dfs(i, node, days, adj);
        days++;
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    adj[1].push_back(-1);

    ll ans = 0;
    dfs(1, -1, ans, adj);
    cout << ans;

}