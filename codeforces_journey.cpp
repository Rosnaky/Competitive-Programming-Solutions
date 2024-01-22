#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


double dfs(int node, int par, vector<vector<int>>& adj) {
    double distance = 0;
    int routes = 0;

    for (int c : adj[node]) {
        if (c != par) {
            distance += dfs(c, node, adj) + 1;
            routes++;
        }
    }

    if (routes == 0) return 0;
    return distance / routes;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; i++) 
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout.precision(numeric_limits<double>::max_digits10);
    cout << dfs(1, 0, adj);
}