#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> par;
vector<vector<pair<int, int>>> rnk;

int Find(int i, int j) {
    if (par[i][j] == par.size()*i+j) return par[i][j];

    return par[i][j] = Find(par[i][j]/par.size(), par[i][j]%par.size());
}

bool Union(int i, int j, int p, int q) {
    int a = Find(i, j);
    int b = Find(p, q);
    // cout << i << j << ":" << a << " " << b << endl;

    if (a != b) {
        par[a/par.size()][a%par.size()] = b;
        rnk[b/par.size()][b%par.size()].first += rnk[a/par.size()][a%par.size()].first;
        return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);

    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    
    for (auto & v : grid) {
        for (auto & g : v) cin >> g;
    }

    vector<vector<int>> edges;

    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (vector<int> & d : dirs) {
                int nrow = i + d[0], ncol = j + d[1];
                if (nrow < 0 || ncol < 0 || nrow >= n || ncol >= n) continue;

                edges.push_back({i, j, nrow, ncol, abs(grid[i][j] - grid[nrow][ncol])});
            }
        }
    }

    par = vector<vector<int>>(n, vector<int>(n));
    rnk = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            par[i][j] = i*n+j;
            rnk[i][j] = {1, 0};
        }
    }

    sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[4] < b[4];
    });

    for (int i = 0; i < edges.size(); i++) {
        if (Union(edges[i][0], edges[i][1], edges[i][2], edges[i][3])) {
            int p = Find(edges[i][0], edges[i][1]);
            rnk[p/n][p%n].second = max(rnk[p/n][p%n].second, edges[i][4]);
            
            if (rnk[p/n][p%n].first * 2 + 1 > n * n) {
                cout << rnk[p/n][p%n].second << '\n';
                return 0;
            }
        }
    }
}