#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

set<int> ans;
vector<vector<int>> graph;

void dfs(int start, int node, vector<bool>& seen, bool& hasCycle) {
    seen[node] = true;

    for (auto n : graph[node]) {
        if (n == start && seen[n]) {
            hasCycle = true;
            return;
        }
        else if (!seen[n]) {
            dfs(start, n, seen, hasCycle);
        }
    }    
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    graph = vector<vector<int>>(n+1);
    
    for (int i = 0; i < k; i++) {
        int a, b, sa, sb;
        cin >> a >> b >> sa >> sb;

        if (sa > sb) {
            graph[a].push_back(b);
        }
        if (sb > sa) {
            graph[b].push_back(a);
        }
    }

    int total = 0;
    for (int i = 1; i <= n; i++) {
        vector<bool> seen(n+1);
        bool hasCycle = false;
        dfs(i, i, seen, hasCycle);

        total += hasCycle;
    }

    cout << total;
    
}