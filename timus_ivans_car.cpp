#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
#define BIG ll(1e15)

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, bool>>> edges(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back({b, 0});
        edges[b].push_back({a, 1});
    }
    int start, end;
    cin >> start >> end;

    vector<ll> dist(n+1, BIG);
    // vector<bool> seen(n+1);
    priority_queue<pair<ll, vector<int>>> queue;
    dist[start] = 0;
    queue.push({0, {start, 0}});
    queue.push({0, {start, 1}});

    while (!queue.empty()) {
        int node = queue.top().second[0], state = queue.top().second[1];
        queue.pop();

        // if (seen[node]) continue;
        // seen[node] = true;

        for (pair<int, bool>& u : edges[node]) {
            int b = u.first, down = u.second;
            if (down == state && dist[b] > dist[node]) {
                dist[b] = dist[node];
                queue.push({-dist[b], {b, down}});
            }
            else if (dist[b] > dist[node]+1) {
                dist[b] = dist[node]+1;
                queue.push({-dist[b], {b, down}});
            }
        }

        // for (int c : dist) cout << c << " ";
        // cout << endl;
    }

    cout << dist[end];
}