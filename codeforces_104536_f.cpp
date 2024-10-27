#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

pair<int, int> far(vector<vector<int>>& adj, int node) {
    int dist = -1, ans = node;

    queue<int> queue;
    queue.push(node);
    vector<bool> seen(adj.size()+1);
    seen[node] = 1;

    while (!queue.empty()) {
        dist++;
        int m = queue.size();

        while (m--) {
            ans = queue.front(); queue.pop();

            for (int a : adj[ans]) {
                if (!seen[a]) queue.push(a);
                seen[a] = 1;
            }
        }
    }

    return {dist, ans};
}

int diameter(vector<vector<int>>& edges) {
    int n = edges.size()+2;
    vector<vector<int>> adj(n);

    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    pair<int, int> a = far(adj, 1);
    // cout << a.first << " " << a.second << endl;
    return far(adj, a.second).first;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> tree1(n-1, vector<int>(2));
    for (int i = 0; i < n-1; i++) {
        cin >> tree1[i][0] >> tree1[i][1];
    }
    int m; cin >> m;
    vector<vector<int>> tree2(m-1, vector<int>(2));
    for (int i = 0; i < m-1; i++) {
        cin >> tree2[i][0] >> tree2[i][1];
    }

    int a = diameter(tree1), b = diameter(tree2);

    cout << max(max(a, b), (a == 2 ? 1 : a/2 + a%2) + (b == 2 ? 1 : b/2 + b%2) + 1) << endl;
}