#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;
typedef long long ll;

ll maxFlow(vector<vector<ll>>& g, int n, int source) {
    ll flow = 0;
    vector<int> par(n+1, -1);

    auto reachable = [&]() -> bool {
        queue<int> queue;
        queue.push(source);
        while(!queue.empty()) {
            int node = queue.front(); queue.pop();
            for (int child = 1; child <= n; child++) {
                ll w = g[node][child];
                if (w <= 0 || par[child] != -1) continue;
                par[child] = node;
                queue.push(child);
            }
        }
        return par[n] != -1;
    };

    while (reachable()) {
        int node = n;
        ll currFlow = LLONG_MAX;
        while (node != source) {
            currFlow = min(currFlow, g[par[node]][node]);
            node = par[node];
        }
        node = n;
        while (node != source) {
            g[par[node]][node] -= currFlow;
            g[node][par[node]] += currFlow;
            node = par[node];
        }
        flow += currFlow;
        fill(par.begin(), par.end(), -1);
    }
    return flow;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<ll>> capacity(n+1, vector<ll>(n+1));

    for (int i = 0; i < m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        capacity[x][y] += c;
    }

    cout << maxFlow(capacity, n, 1);
}