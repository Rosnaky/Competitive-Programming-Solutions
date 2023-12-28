#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
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

    int ans = 0;
    vector<bool> seen(n+1);

    queue<int> queue;
    
    for (int i = 1; i <= n; i++) {
        if (seen[i]) continue;

        queue.push(i);

        while (!queue.empty()) {
            int node = queue.front();
            queue.pop();
            
            ans += 1;

            seen[node] = true;

            for (int a : graph[node]) {
                if (seen[a]) continue;
                queue.push(a);
            }
        }
    }

    cout << ans;
}