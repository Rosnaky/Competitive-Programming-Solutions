#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Edge{
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator<(Edge const& other) {
        return w < other.w;
    }
};

vector<int> par;
vector<int> rnk;

int Find(int a) {
    if (par[a] == a) return a;
    return par[a] = Find(par[a]);
}

bool Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a != b) {
        if (rnk[a] < rnk[b]) {
            swap(a, b);
        }
        par[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;

        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("computersites.in", "r", stdin);

    int n;
    cin >> n;
    rnk.assign(n+1,1);
    par.assign(n+1,0);
    for (int i = 0; i < n; i++) par[i] = i;

    

    int ans1 = 0;
    for (int i = 0; i < n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
    }

    vector<Edge> newEdges;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        newEdges.push_back(Edge(a, b, c));
    }

    vector<Edge> oldEdges;
    
    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        oldEdges.push_back(Edge(a, b, c));
    }

    sort(oldEdges.begin(), oldEdges.end());

    int ans = 0;
    for (Edge& e : oldEdges) {
        if (Union(e.u, e.v)) {
            ans += e.w;
        }
    }
    cout << ans << "\n";

    for (Edge e : newEdges) oldEdges.push_back(e);

    sort(oldEdges.begin(), oldEdges.end());

    rnk.assign(n+1,1);
    par.assign(n+1,0);
    for (int i = 0; i < n; i++) par[i] = i;

    ans = 0;
    for (Edge& e : oldEdges) {
        if (Union(e.u, e.v)) {
            ans += e.w;
        }
    }
    cout << ans << "\n";
}