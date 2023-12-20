#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

using namespace std;

struct edge {
    int u, v, l, w;
    edge(int u, int v, int l, int w) : u(u), v(v), l(l), w(w) {}
};

struct edgeComparator {
    bool operator()(const edge& edge1, const edge& edge2) const {
        return edge1.l > edge2.l;
    }
};


const int N = 2005;
vector<int> par, rnk;
vector<vector<pair<int, int>>> graph;
vector<edge> edges;

void make_set(int n) {
    par[n] = n;
    rnk[n] = 1;
}

int find(int n) {
    if (par[n] == n) {
        return n;
    }

    return par[n] = find(par[n]);
}

bool Union(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        if (rnk[a] > rnk[b]) {
            par[b] = a;
        }
        else {
            if (rnk[a] == rnk[b]) {
                rnk[b]++;
            }
            par[a] = b;
        }

        return true;
    }

    return false;
}

int shortestPath(int u, int v, set<int> seen) {
    if (u == v) {
        return 0;
    }

    seen.insert(u);
    int minPath = 1e9;

    for (pair<int, int> p : graph[u]) {
        int next = p.first, len = p.second;
        if (seen.find(next) != seen.end()) {
            continue;
        }
        minPath = min(minPath, len + shortestPath(next, v, seen)) + graph[u][next].second;
    }

    return minPath;
}

int pathCost(int u, int v, set<int> seen) {
    if (u == v) {
        return 0;
    }

    seen.insert(u);
    int minPath = 1e9;

    for (pair<int, int> p : graph[u]) {
        int next = p.first, len = p.second;
        if (seen.find(next) != seen.end()) {
            continue;
        }
        minPath = min(minPath, len + shortestPath(next, v, seen)) + graph[u][next].first;
    }

    return minPath;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    par = vector<int>(N);
    rnk = vector<int>(N);
    graph = vector<vector<pair<int, int>>>(N);
    edges = vector<edge>();

    for (int i = 1; i <= n; i++) {
        make_set(i);
    }

    for (int i = 0; i < m; i++) {
        int u, v, l, w;
        cin >> u >> v >> l >> w;

        edges.push_back(edge(u, v, l, w));
        graph[u].push_back(make_pair(u, l));
        graph[v].push_back(make_pair(u, l));
    }

    sort(edges.begin(), edges.end(), edgeComparator());
    int minCost = 0;

    for (edge e : edges) {
        int u = e.u, v = e.v, l = e.l, w = e.w;

        if (graph[u].size() == 1 || graph[v].size() == 1) {
            minCost += w;
        }
        
        if (Union(u, v)) {
            int temp = shortestPath(u, v, set<int>()); 
            if (temp < l) {
                minCost += w;
            }

            if (temp == l && pathCost(u, v, set<int>()) > w) {
                minCost += w;
            }
        }
        cout << minCost << endl;
    }

    cout << minCost << endl;

}