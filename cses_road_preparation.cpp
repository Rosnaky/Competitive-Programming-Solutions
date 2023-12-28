#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}

    bool operator<(Edge const& other) {
        return w < other.w;
    }
};


vector<Edge> edges;
vector<int> par;
vector<int> rnk;


void makeSet(int n) {
    par[n] = n;
    rnk[n] = 1;
}

int Find(int i) {
    if (par[i] == i) return i;
    return par[i] = Find(par[i]);
}

bool Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a!=b) {
        if (rnk[a] < rnk[b]) {
            swap(a, b);
        }
        par[b] = a;
        if (rnk[a] == rnk[b]) {
            rnk[a]+=1;
        }
        return true;
    }
    return false;
}

int dfs(int i, vector<bool>& seen, vector<vector<int>>& graph) {
    seen[i] = true;
    int ans = 1;
    for (int a : graph[i]) {
        if (!seen[a]) {
            ans += dfs(a, seen, graph);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);

    par = vector<int>(n+1);
    rnk = vector<int>(n+1);

    for (int i = 1; i <= n; i++) makeSet(i);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> seen(n+1);
    if (dfs(1, seen, graph) != n) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    sort(edges.begin(), edges.end());
    ll cost = 0;
    for (Edge e : edges) {
        if (Union(e.u, e.v)) {
            cost += e.w;
        }
    }

    cout << cost;
}