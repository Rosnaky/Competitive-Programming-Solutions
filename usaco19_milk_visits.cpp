#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);


    int n, m; cin >> n >> m;
    string s; cin >> s;

    vector<vector<int>> adj(n+1);

    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);    
    }



    for (int i = 0; i < m; i++) {
        int start, end; char cow; cin >> start >> end >> cow;

        queue<pair<int, bool>> queue;
        vector<bool> seen(n+1);
        queue.push({start, 0});
        bool good = 0;

        while (!queue.empty()) {
            auto [node, valid] = queue.front();
            queue.pop();

            if (cow == s[node-1]) {
                valid = true;
            }
            if (node == end) {
                good = valid;
                break;
            }
            seen[node] = true;

            for (int next : adj[node]) {
                if (seen[next]) continue;
                queue.push({next, valid});
            }
        }

        if (good) {
            cout << 1;
        }
        else {
            cout << 0;
        }
    }

}