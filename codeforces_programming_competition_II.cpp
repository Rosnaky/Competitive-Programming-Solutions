#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> graph;
int n;
int sz[222222];

void init(int v) {
  sz[v] = 1;
  for (int u : graph[v]) {
    init(u);
    sz[v] += sz[u];
  }
}
 
int calc(int v, int k) {
  int tot = 0, mx = -1;
  for (int u : graph[v]) {
    tot += sz[u];
    if (mx == -1 || sz[mx] < sz[u]) mx = u;
  }
  if (tot == 0) return 0;
  if (sz[mx] - k <= tot - sz[mx])
    return (tot - k) / 2;
  int add = tot - sz[mx];
  return add + calc(mx, max(0, k + add - 1));
}



void solve() {
    cin >> n;

    graph = vector<vector<int>>(n+1);

    for (int i = 2; i <= n; i++) {
        int temp; cin >> temp;
        graph[temp].push_back(i);
    }

    init(0);
    cout << calc(0, 0) << "\n";

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}