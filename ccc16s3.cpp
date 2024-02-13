#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <queue>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> pho;
    vector<bool> isPho(n);
    for (int i = 0; i < m; i++) {
        int temp; cin >> temp;
        pho.push_back(temp);
        isPho[temp] = true;
    }

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    queue<int> queue;
    queue.push(pho[0]);
    vector<bool> seen(n);
    // vector<int> dist(n, 1e9);
    long long ans = 0;
    long long curr = 0;

    while (!queue.empty()) {

        int s = queue.size();
        curr++;

        for (int i = 0; i < s; i++) {
            int node = queue.front();
            queue.pop();

            if (seen[node]) continue;
            seen[node] = true;

            for (int e : adj[node]) {
                queue.push(e);
            }

            for (int e : adj[node]) {
                if (isPho[e]) {
                    ans += curr;
                    curr = 0;
                    std::queue<int> temp;
                    swap(queue, temp);
                    queue.push(e);
                    break;
                }
            }
        }
    }

    cout << ans;
}