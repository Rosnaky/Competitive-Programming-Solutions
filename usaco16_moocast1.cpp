#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int calcDistance(int x, int y, int a, int b) {
    return (x-a)*(x-a) + (y-b)*(y-b);
}

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

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int n;
    cin >> n;

    par.assign(n, 0);
    rnk.assign(n, 1);

    vector<pair<int, int>> cows;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cows.push_back({a, b});
        par[i] = i;
    }


    vector<Edge> graph;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            // cout << i << " " << j << endl;
            graph.push_back(Edge(i, j, calcDistance(cows[i].first, cows[i].second, cows[j].first, cows[j].second)));
        }
    }
    sort(graph.begin(), graph.end());

    int ans = 1e9;
    for (Edge& e : graph) {
        if (Union(e.u, e.v)) {
            ans = e.w;
        }
    }

    cout << ans;
}