#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

int dfs(int i, vector<int>& ans, vector<vector<int>>& adj) {
    if (ans[i] != -1) return ans[i];

    int sum = 0;
    for (int c : adj[i]) {
        sum += dfs(c, ans, adj) + 1;
    }
    return ans[i] = sum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> adj(n+1);

    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        adj[p].push_back(i);
    }

    vector<int> ans(n+1, -1);

    for (int i = 1; i <= n; i++) {
        dfs(i, ans, adj);
    }
    for (int a = 1; a <= n; a++) cout << ans[a] << " ";
}