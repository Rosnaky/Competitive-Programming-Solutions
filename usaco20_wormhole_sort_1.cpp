#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> par;
// vector<int> rnk;

int Find(int n) {
    if (par[n] == n) return n;

    return par[n] = Find(par[n]);
}

bool Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a == b) return false;
    
    // rnk[b] += rnk[a];
    par[a] = b;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);

    int n, m; cin >> n >> m;

    par = vector<int>(n+1);
    for (int i = 1; i<= n; i++) {
        par[i] = i;
    }

    vector<int> pos(n);
    for (int &i : pos) cin >> i;
    
    vector<vector<int>> edges(m, vector<int>(3));
    for (auto & v : edges) {
        cin >> v[0] >> v[1] >> v[2];
    }

    sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {return a[2] > b[2];});

    int needsSort = 0;
    for (int i = 0; i < n; i++) {
        needsSort += (pos[i] != i+1);
    }

    if (!needsSort) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i < m; i++) {
        int a = edges[i][0], b = edges[i][1], w = edges[i][2];
        
        Union(a, b);

        bool good = 1;
        for (int i = 1; i <= n; i++) {
            if (Find(i) != Find(pos[i-1])) {
                good = 0;
                break;
            }
        }

        if (good) {
            cout << w << '\n';
            return 0;
        }
    }

}