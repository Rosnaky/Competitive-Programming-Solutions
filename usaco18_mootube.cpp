#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    int n, q; cin >> n >> q;

    vector<vector<pair<int, int>>> adj(n+1);

    for (int i = 0; i < n-1; i++) {
        int a, b, r; cin >> a >> b >> r;
        adj[a].push_back({b, r});
        adj[b].push_back({a, r});
    }

    for (int i = 0; i < q; i++) {
        int k, v; cin >> k >> v;

        queue<pair<int, int>> queue;
        queue.push({v, 1e9});
        vector<bool> seen(n+1);
        int ans = -1;

        while (!queue.empty()) {
            auto [node, relevance] = queue.front();
            queue.pop();

            if (seen[node]) continue;
            seen[node] = true;

            if (relevance >= k) ans++;

            for (pair<int, int>& c : adj[node]) {
                if (seen[c.first]) continue;
                queue.push({c.first, min(relevance, c.second)});
            }
        }

        cout << ans << "\n";
    }

}