#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;
typedef long long ll;

int n, m;
vector<vector<bool>> grid;
vector<vector<bool>> seen;
vector<vector<vector<pair<int, int>>>> edges;
vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
ll ans = 1;

void dfs(int row, int col) {
    
    if (!grid[row][col] || seen[row][col]) return;
    seen[row][col] = true;

    for (pair<int, int>& e : edges[row][col]) {
        if (grid[e.first][e.second]) continue;
        grid[e.first][e.second] = true;
        ans++;
        for (pair<int, int>& d : dirs) {
            int nRow = e.first+d.first, nCol = e.second+d.second;
            if (nRow <= 0 || nRow > n || nCol <= 0 || nCol > n) continue;
            if (seen[nRow][nCol]) {
                dfs(e.first, e.second);
                break;
            }
        }
    }

    for (pair<int, int>& d : dirs) {
        int nRow = row+d.first, nCol = col+d.second;
        if (nRow <= 0 || nRow > n || nCol <= 0 || nCol > n) continue;
        dfs(nRow, nCol);
    }
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);

    cin >> n >> m;
    seen = vector<vector<bool>>(n+1, vector<bool>(n+1));
    grid = vector<vector<bool>>(n+1, vector<bool>(n+1)); grid[1][1] = true;
    edges = vector<vector<vector<pair<int, int>>>>(n+1, vector<vector<pair<int, int>>>(n+1));

    for (int i = 0; i < m; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        edges[a][b].push_back({c, d});
    }
    dfs(1, 1);
    cout << ans;
}