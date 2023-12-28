#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


struct Edge {
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

struct EdgeComparator {
    bool operator()(const Edge& e1, const Edge& e2) {
        return e1.w < e2.w;
    }
};


vector<Edge> edges;
vector<int> par;
vector<int> rnk;

int Find(int x) {
    if (par[x] == x) {
        return x;
    }

    return par[x] = Find(par[x]);
}

bool Union(int u, int v) {
    u = Find(u);
    v = Find(v);

    if (u != v) {
        if (rnk[u] > rnk[v]) {
            par[v] = u;
        }
        else {
            if (rnk[u] == rnk[v]) {
                rnk[v]++;
            }
            par[u] = v;
        }
        return true;
    }

    return false;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        par[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        edges.push_back(Edge(u, v, w));
    }

    sort(edges.begin(), edges.end(), EdgeComparator());


    int cost = 0;

    for (Edge e : edges) {
        int u = e.u, v = e.v, w = e.w;
        if (Union(u, v)) {
            cost += w;
        }
    }
}