#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
// TODO: Use MST
int n, m;
vector<vector<int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int dfs(int row, int col, int needed, int curr, vector<vector<bool>> seen, vector<vector<int>>& grid, vector<vector<bool>>& points) {
    if (seen[row][col]) return 1e9;
    if (points[row][col]) {
        needed--;
    }
    if (needed == 0) {
        return curr;
    }

    seen[row][col] = true;
    int ans = 1e9;
    for (auto dir : dirs) {
        if (row+dir[0] < 0 || row+dir[0] >= n || col+dir[1] < 0 || col+dir[1] >= m) continue;
        ans = min(ans, dfs(dir[0]+row, dir[1]+col, needed, max(curr, abs(grid[row][col]-grid[dir[0]+row][dir[1]+col])), seen, grid, points));
    }
    return ans;
}


int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);

     cin >> n >> m;

    vector<vector<int>> elevations(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> elevations[i][j];
        }
    }

    int needed = 0;
    vector<vector<bool>> point(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp; cin >> temp;
            point[i][j] = temp;
            needed += temp;
        }
    }
    
    int ans = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!point[i][j]) continue;
            
            vector<vector<bool>> seen(n, vector<bool>(m));
            cout << dfs(i, j, needed, 0, seen, elevations, point);
            return 0;
        }
    }
    
}