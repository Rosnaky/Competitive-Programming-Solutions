#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

#define BIG ll(1e15)


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, w, d;
    cin >> n >> w >> d;

    vector<vector<int>> graph(n+1);
    for (int i = 0; i < w; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        // graph[b].push_back(a);
    }

    vector<int> subway(n);
    for (int i = 0; i < n; i++) {
        cin >> subway[i];
    }


    for (int i = 0; i < d; i++) {
        int x, y; cin >> x >> y; x--, y--;
        swap(subway[x], subway[y]);
        // for (int a : subway) cout << a << " "; cout << endl;

        vector<ll> dist(n+1, BIG);
        dist[1] = 0;
        queue<pair<int, int>> queue;
        queue.push({1, 0});

        while (!queue.empty()) {
            int node = queue.front().first, time = queue.front().second; queue.pop();

            for (int u : graph[node]) {
                if (dist[u] > dist[node]+1) {
                    dist[u] = dist[node]+1;
                    queue.push({u, dist[u]});
                }
            }
            if (time < n-1 && subway[time] == node && dist[subway[time+1]] > dist[subway[time]] + 1) {
                dist[subway[time+1]] = dist[subway[time]] + 1;
                queue.push({subway[time+1], dist[subway[time+1]]});
            }
        }

        cout << dist[n] << "\n";
    }
}