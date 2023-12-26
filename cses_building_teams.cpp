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

    vector<int> team(n+1, -1);

    
    for (int i = 1; i <= n; i++) {
        if (team[i] != -1) continue;

        queue<vector<int>> queue;
        queue.push({i, 1});

        while (!queue.empty()) {
            vector<int> curr = queue.front();
            queue.pop();

            int node = curr[0], t = curr[1];

            team[node] = t;

            for (int a : graph[node]) {
                if (team[a] == team[node]) {
                    cout << "IMPOSSIBLE";
                    exit(0);
                }
                else if (team[a] == (team[node]+1)%2) continue;

                queue.push({a, (t+1)%2});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << team[i]+1 << " ";
    }
}