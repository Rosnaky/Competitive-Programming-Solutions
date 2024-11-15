#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, int par, int id, vector<vector<int>>& dist, vector<vector<int>>& adj) {
    for (int i : adj[node]) {
        if (i == par) continue;

        dist[id][i] = max(dist[id][i], dist[id][node]+1);
        dfs(i, node, id, dist, adj);
    }
}

int getFar(int id, vector<vector<int>>& dist) {
    int ans = 1, d = 0;
    for (int i = 1; i < dist[0].size(); i++) {
        if (d < dist[id][i]) {
            d = dist[id][i];
            ans = i;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<vector<int>> dist(3, vector<int>(n+1));
    dfs(1, 1, 0, dist, adj);

    int farone = getFar(0, dist);
    dfs(farone, farone, 1, dist, adj);
    int fartwo = getFar(1, dist);
    dfs(fartwo, fartwo, 2, dist, adj);



    for (int i = 1; i <= n; i++) {
        cout << max(dist[1][i], dist[2][i]) << " ";
    }


}