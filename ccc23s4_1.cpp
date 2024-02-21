#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

struct Edge {
    int u, v, c, l;
    Edge(int u, int v, int l, int c) : u(u), v(v), l(l), c(c) {}
};

struct EdgeComparator {
    bool operator()(const Edge& edge1, const Edge& edge2) const {
        return edge1.l < edge2.l;
    }
};
struct EdgeComparator1 {
    bool operator()(const Edge& edge1, const Edge& edge2) const {
        return edge1.c < edge2.c;
    }
};

vector <int> par, rnk;
int n, m; 
vector<bool> edgesUsed;


void makeSet(int n) {
    par[n] = n;
    rnk[n] = 1;
}

int Find(int n) {
    if (par[n] == n) return n;
    return par[n] = Find(par[n]);
}


ll dfs(int a, int target, vector<Edge>& edges) {
    vector<bool> seen(n+1);
    priority_queue<pair<ll, int>> queue;
    queue.push({0, a});
    while (!queue.empty()) {
        int node = queue.top().second; ll dist = queue.top().first;
        
        if (node == target) return -queue.top().first;
        queue.pop();

        if (seen[node]) continue;
        seen[node] = true;

        for (int i = 0; i < m; i++) {
            if (!edgesUsed[i]) continue;
            Edge e = edges[i];

            if (e.u == node) {
                queue.push({dist-e.l, e.v});
            }
            else if (e.v == node) {
                queue.push({dist-e.l, e.u});
            }
        }

    }
    return 1e15;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    par = vector<int>(n+1);
    rnk = vector<int>(n+1);
    vector<Edge> edges;
    edgesUsed = vector<bool>(m);

    for (int i = 1; i <= n; i++) makeSet(i);
    
    for (int i = 0; i < m; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        edges.push_back(Edge(a, b, c, d));
    }
    sort(edges.begin(), edges.end(), EdgeComparator1());
    sort(edges.begin(), edges.end(), EdgeComparator());

    ll ans = 0;
    for (int i = 0; i < m; i++) {
        int a = Find(edges[i].u);
        int b = Find(edges[i].v);
        if (a != b) {
            edgesUsed[i] = true;
            // cout << edges[i].v << " " << edges[i].u << endl;
            ans += edges[i].c;
            
            if (rnk[a] > rnk[b]) par[b] = a;
            else {
                if (rnk[a] == rnk[b]) rnk[b]++;
                par[a] = b;
            }
        }
        else {
            // cout << edges[i].u << " " << edges[i].v << " " << dfs(edges[i].u, edges[i].v, edges) << endl;
            if (edges[i].l < dfs(edges[i].u, edges[i].v, edges)) {
                edgesUsed[i] = true;
                ans += edges[i].c;
            }
        }
    }

    cout << ans;
}