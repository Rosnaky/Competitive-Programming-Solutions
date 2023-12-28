#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;
typedef long long ll;
#define BIG LLONG_MAX

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> graph(n+1);
    for (int i = 0; i < m; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
    }

    priority_queue<pair<ll, ll>> queue;
    vector<ll> distance(n+1, BIG);
    vector<bool> processed(n+1);
    distance[1] = 0;

    queue.push({0, 1});

    while (!queue.empty()) {
        int node = queue.top().second; queue.pop();

        if (processed[node]) continue;
        processed[node] = true;

        for (auto i : graph[node]) {
            ll a = i.first, w = i.second;
            if (distance[node]+w < distance[a]) {
                distance[a] = distance[node]+w;
                queue.push({-distance[a], a});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << distance[i] << " ";
    }
}