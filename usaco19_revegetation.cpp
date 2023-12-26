#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> diff(n+1);
    vector<vector<int>> same(n+1);

    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> c >> a >> b;
        if (c == 'D') {
            diff[a].push_back(b);
            diff[b].push_back(a);
        }
        else {
            same[a].push_back(b);
            same[b].push_back(a);
        }
    }

    vector<int> grass(n+1, -1);
    // vector<bool> seen(n+1, false);

    for (int i = 1; i <= n; i++) {
        if (grass[i] != -1) continue;

        queue<vector<int>> queue;
        queue.push({i, 0});

        while (!queue.empty()) {
            vector<int> curr = queue.front();
            queue.pop();

            int node = curr[0], team = curr[1];

            grass[node] = team;

            for (int e : diff[node]) {
                if (grass[e] == grass[node]) {
                    cout << "here";
                    cout << 0;
                    exit(0);
                }
                else if (grass[e] == (grass[node]+1)%2) continue;

                queue.push({e, (team+1)%2});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int e : same[i]) {
            if (grass[i] != grass[e]) {
                cout << 0;
                exit(0);
            }
        }
    }

    cout << 10;
}