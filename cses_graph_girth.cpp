#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }


    int ans = 1e9;

    for (int i = 1; i <= n; i++) {
        vector<int> distance(n+1, 1e9);

        queue<int> queue;
        queue.push(i);
        distance[i] = 0;


        while (!queue.empty()) {
            int node = queue.front();
            queue.pop();

            for (int a : graph[node]) {
                if (distance[a] == 1e9) {
                    distance[a] = distance[node]+1;
                    queue.push(a);
                }

                else if (distance[a] >= distance[node]) {
                    ans = min(ans, distance[node]+1+distance[a]);
                }
            }
        }
    }

    if (ans == 1e9) {
        cout << -1;
    }
    else {
        cout << ans;
    }
}