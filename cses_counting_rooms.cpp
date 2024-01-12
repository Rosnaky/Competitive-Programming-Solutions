#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> seen;

void dfs(int i, int j) {
    if (i >= n || i < 0 || j >= m || j < 0 || !grid[i][j] || seen[i][j]) return;

    seen[i][j] = true;

    dfs(i+1, j); dfs(i-1, j); dfs(i, j+1); dfs(i, j-1);
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    grid = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '.') grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }

    seen = vector<vector<bool>>(n, vector<bool>(m));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!seen[i][j] && grid[i][j]) {
                dfs(i, j);
                ans++;
            }
        }
    }

    cout << ans;
}