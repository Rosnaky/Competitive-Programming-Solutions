#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;
#define BIG ll(1e15)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> graph(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }


    vector<ll> ans;
    // vector<ll> dist(n+1, BIG);
    vector<bool> seen(n+1);
    // dist[1] = 0;
    priority_queue<pair<ll, int>> queue;
    queue.push({0, 1});

    while (!queue.empty()) {
        int node = queue.top().second, price = queue.top().first*-1;
        queue.pop();

        if (node == n) {
            ans.push_back(price);
        }
        // if (seen[node]) continue;
        // seen[node] = true;
        if (ans.size() == k) break;

        for (pair<int, int>& i : graph[node]) {
            int b = i.first, w = i.second;
            queue.push({-(price+w), b});
        }
    }

    sort(ans.begin(), ans.end());
    for (int a : ans) cout << a << " ";
}