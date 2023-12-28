#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
#define BIG int(1e9)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> graph(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    vector<int> trains(n+1);
    vector<int> trainI;
    for (int i = 0; i < k; i++) {
        int s, y;
        cin >> s >> y;
        trains[s] = y;
        trainI.push_back(s);
    }


    vector<int> dist(n+1, BIG);
    vector<bool> seen(n+1);
    dist[1] = 0;
    priority_queue<pair<int, int>> queue;
    queue.push({0, 1});

    while (!queue.empty()) {
        int node = queue.top().second;
        queue.pop();

        if (seen[node]) continue;
        seen[node] = true;

        for (pair<int, int>& u : graph[node]) {
            int b = u.first, w = u.second;
            if (dist[b] > dist[node]+w) {
                dist[b] = dist[node]+w;
                queue.push({-dist[b], b});
            }
        }
        if (node == 1) {
            for (int b : trainI) {
                int w = trains[b];
                if (dist[b] > dist[node]+w) {
                    dist[b] = dist[node]+w;
                    queue.push({-dist[b], b});
                }
            }
        }
    }

    

    seen = vector<bool>(n+1);
    queue.push({0, 1});
    int ans = 0;

    for (int i : trainI) {
        int temp = trains[i];
        trains[i] = BIG;

        vector<int> dist1(n+1, BIG);
        dist1[1] = 0;

        while (!queue.empty()) {
            int node = queue.top().second;
            queue.pop();

            if (seen[node]) continue;
            seen[node] = true;

            if (node == i) {
                if (dist[i] == dist1[i]) {
                    ans++;
                }
                break;
            }

            for (pair<int, int>& u : graph[node]) {
                int b = u.first, w = u.second;
                if (dist1[b] > dist1[node]+w) {
                    dist1[b] = dist1[node]+w;
                    queue.push({-dist1[b], b});
                }
            }
            if (node == 1) {
                for (int b : trainI) {
                    int w = trains[b];
                    if (dist1[b] > dist1[node]+w) {
                        dist1[b] = dist1[node]+w;
                        queue.push({-dist1[b], b});
                    }
                }
            }
        }

        trains[i] = temp;
    }

    cout << ans;
}