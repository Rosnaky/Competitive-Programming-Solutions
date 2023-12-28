#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;
#define mod int(1e9+7)
#define BIG 9223372036854775807

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n+1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    priority_queue<pair<ll, vector<ll>>> queue;
    queue.push({0, {1, 0}}); // price, {node, flights}

    vector<vector<ll>> distance(n+1, {BIG, 0, BIG, 0}); //price, numRoutes, minFlights, maxFlights
    distance[1][0] = 0;
    distance[1][1] = 0;
    distance[1][2] = 0;

    vector<bool> seen(n+1);

    while (!queue.empty()) {
        ll node = queue.top().second[0], flights = queue.top().second[1];
        queue.pop();
        
        if (seen[node]) continue;
        seen[node] = true;

        for (auto next : graph[node]) {
            auto [dest, flightCost] = next;

            if (distance[dest][0] > distance[node][0]+flightCost) {
                distance[dest] = {distance[node][0]+flightCost, 1, flights+1, flights+1};
                queue.push({-distance[dest][0], {dest, flights+1}});
            }
            if (distance[dest][0] == distance[node][0]+flightCost) {
                distance[dest][1] = (distance[dest][1] + distance[node][1]) % mod;
                distance[dest][2] = min(distance[dest][2], flights+1);
                distance[dest][3] = max(distance[dest][3], flights+1);
            }
        }
    }

    cout << distance[n][0] << " " << distance[n][1] << " " << distance[n][2] << " " << distance[n][3];
}