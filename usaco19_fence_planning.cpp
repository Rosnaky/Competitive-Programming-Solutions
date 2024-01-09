#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("fenceplan.in", "r", stdin); freopen("fenceplan.out", "w",stdout);

    int n, m; cin >> n >> m;
    vector<pair<int, int>> cows(n+1);
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        cows[i] = {x, y};
    }

    vector<vector<int>> graph(n+1);
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> seen(n+1);
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        if (seen[i]) continue;

        int x1 = 1e9, x2 = -1, y1 = 1e9, y2 = -1;

        stack<int> stack;
        stack.push(i);

        while (!stack.empty()) {
            int node = stack.top(); stack.pop();

            if (seen[node]) continue;
            seen[node] = true;

            x1 = min(x1, cows[node].first);
            y1 = min(y1, cows[node].second);

            x2 = max(x2, cows[node].first);
            y2 = max(y2, cows[node].second);

            for (int a : graph[node]) {
                stack.push(a);
            }
        }

        ans = min(ans, 2*(x2-x1)+2*(y2-y1));
    }
    cout << ans;
}