#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n;
map<vector<int>, int> memo;

int dfs(vector<int> positions, vector<vector<pair<int, int>>>& graph, int curr) {
    if (memo.count(positions)) return min(curr, memo[positions]);
    for (int i = 1; i <= n; i++) {
        if (positions[i] != i+1) break;
        if (i == n) {
            if (curr == 1e9) cout << -1;
            else cout << curr;
        }
    }
    int ans = -1;
    for (int a = 1; a <= n; a++) {
        for (auto p : graph[a]) {
            int w = p.first, b = p.second;
            vector<int> temp = positions;
            swap(temp[a], temp[b]);
            memo[positions] = max(ans, dfs(temp, graph, min(curr, w)));
            ans = min(ans, memo[positions]);
        }
    }
    return ans;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);

    int m;
    cin >> n >> m;

    vector<int> positions(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> positions[i];
    }

    vector<vector<pair<int, int>>> graph(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({w, b});
        graph[b].push_back({w, a});
    }

    cout << dfs(positions, graph, 1e9);
}