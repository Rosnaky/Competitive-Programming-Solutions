#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> quals;
vector<int> par;
vector<int> rnk;

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator<(Edge const& other) {
        return w < other.w;
    }
};

void makeSet(int i) {
    par[i] = i;
    rnk[i] = 1;
}

int Find(int i) {
    if (par[i] == i) return i;
    return par[i] = Find(par[i]);
}

bool Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a != b && rnk[a] >= rnk[b]) {
        // if (rnk[a] < rnk[b]) {
        //     swap(a, b);
        // }
        par[b] = a;

        rnk[a] += rnk[b];

        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    quals = vector<int>(n+1);
    par = vector<int>(n+1);
    rnk = vector<int>(n+1);

    for (int i = 1; i <= n; i++) cin >> quals[i], makeSet(i);

    vector<Edge> edges;
    int m; cin >> m;

    if (n == 1 && m == 0) {cout << 0; return 0;}

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back(Edge(a, b, c));
    }

    sort(edges.begin(), edges.end());

    int cost = 0;
    int maxSize = 0;
    for (Edge& e : edges) {
        if (Union(e.u, e.v)) {
            cost += e.w;
            maxSize = max(maxSize, rnk[e.u]);
        }
    }
    cout << maxSize << " " << n << "\n";
    if (maxSize != n) cout << -1;
    else cout << cost;
}