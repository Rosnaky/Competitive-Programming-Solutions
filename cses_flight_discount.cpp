#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;
#define BIG 9223372036854775807

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n+1);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        graph[a].push_back({b, w});
    }

    priority_queue<pair<ll, vector<ll>>> queue;
    queue.push({0, {1, 0}});

    vector<vector<ll>> distance(n+1, vector<ll>(2, BIG));
    vector<vector<bool>> processed(n+1, vector<bool>(2));
    distance[1][0] = 0;

    while (!queue.empty()) {
        int node = queue.top().second[0], coupon = queue.top().second[1];
        queue.pop();

        if (processed[node][coupon]) continue;
        processed[node][coupon] = true;

        for (auto u : graph[node]) {
            ll b = u.first, w = u.second;
            if (distance[node][coupon]+w < distance[b][coupon]) {
                distance[b][coupon] = distance[node][coupon]+w;
                queue.push({-distance[b][coupon], {b, coupon}});
            }
            if (!coupon && distance[node][0]+w/2 < distance[b][1]) {
                distance[b][1] = distance[node][0] + w/2;
                queue.push({-distance[b][1], {b, 1}});
            }
        }
    }

    // for (auto i : distance) {
    //     cout << i[0] << " ";
    // }
    // cout << "\n";
    // for (auto i : distance) {
    //     cout << i[1] << " ";
    // }
    cout << distance[n][1];
}