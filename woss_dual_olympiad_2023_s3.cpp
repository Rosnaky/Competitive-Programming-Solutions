#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;

    vector<vector<int>> graph(n+1);
    for (int i = 1; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a][b] = c;
    }

    vector<set<int>> dist(n+1);
    
    for (int i = 1; i <= n; i++) {
        queue<pair<int, int>> queue;
        queue.push({1, 0});
        vector<bool> seen(n+1);

        while (!queue.empty()) {
            auto [node, d] = queue.front(); queue.pop();

            if (node == i) dist[i].insert(d);

            if (seen[node]) continue;
            node = true;

            


        }
    }


}