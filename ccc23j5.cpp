#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int n, m;
string target;


int dfs(int row, int col, int d, int index, vector<vector<char>>& grid, bool p) {
    if (row < 0 || row >= n || col < 0 || col >= m) return 0;
    if (grid[row][col] != target[index]) return 0;

    if (index == target.size()-1) return 1;
    // {cout << row << " " << col << " " << grid[row][col] << " " << target[index] << endl; return 1;}

    int ans = dfs(row+dirs[d][0], col + dirs[d][1], d, index+1, grid, p);

    if (!p && index != 0 && dirs[d][0] == 0 && abs(dirs[d][1]) == 1) {
        ans += dfs(row+1, col, 1, index+1, grid, true);
        ans += dfs(row-1, col, 3, index+1, grid, true);
    }
    else if (!p && index != 0 && abs(dirs[d][0]) == 1 && dirs[d][1] == 0) {
        ans += dfs(row, col+1, 0, index+1, grid, true);
        ans += dfs(row, col-1, 2, index+1, grid, true);
    }
    else if (!p && index != 0 && ((dirs[d][0] == 1 && dirs[d][1] == -1) || (dirs[d][0] == -1 && dirs[d][1] == 1))) {
        ans += dfs(row-1, col-1, 7, index+1, grid, true);
        ans += dfs(row+1, col+1, 4, index+1, grid, true);
    }
    else if (!p && index != 0) {
        ans += dfs(row-1, col+1, 6, index+1, grid, true);
        ans += dfs(row+1, col-1, 5, index+1, grid, true);
    }

    return ans;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> target;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int dir = 0; dir < dirs.size(); dir++) {
                ans += dfs(i, j, dir, 0, grid, false);
            }
        }
    }
    // ans = dfs(3, 0, 6, 0, grid, false);

    cout << ans;
}