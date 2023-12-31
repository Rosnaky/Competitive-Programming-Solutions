#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int m, n;
vector<vector<int>> grid;
vector<vector<bool>> seen;


bool dfs(int row, int col) {
    if (row == m && col == n) return true;

    if (seen[row][col]) return false;
    seen[row][col] = true;


    for (int i = 1; i <= m; i++) {
        if ((double)grid[row][col]/i <= n && (double)grid[row][col]/i >= 1 && (double)grid[row][col]/i == grid[row][col]/i) {
            if (dfs(i, grid[row][col]/i)) {
                return true;
            }
        }
    }


    return false;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> m >> n;
    
    grid = vector<vector<int>>(m+1, vector<int>(n+1));
    seen = vector<vector<bool>>(m+1, vector<bool>(n+1));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    if (dfs(1, 1)) cout << "yes";
    else cout << "no";
    
}