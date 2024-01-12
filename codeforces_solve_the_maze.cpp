#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

vector<vector<char>> grid;
vector<vector<bool>> seen;
int n, m;

bool dfs(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || seen[i][j]) return true;
    if (grid[i][j] != 'B') {
        if (grid[i][j] == '.' || grid[i][j] == '#') {
            grid[i][j] = '#';
            return true;
        }
        return false;
    }

    seen[i][j] = true;

    
    if (!dfs(i-1, j)) return false;
    if (!dfs(i+1, j)) return false;
    if (!dfs(i, j-1)) return false;
    if (!dfs(i, j+1)) return false;
    return true;
}


void solve() {
    cin >> n >> m;

    grid = vector<vector<char>>(n, vector<char>(m));
    seen = vector<vector<bool>>(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            grid[i][j] = s[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'B' && !seen[i][j]) {
                if (!dfs(i, j)) {
                    cout << "No\n";
                    return;
                }
            }
        }
    }

    
    vector<vector<bool>> good(n, vector<bool>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != 'G' || good[i][j]) continue;
            seen = vector<vector<bool>>(n, vector<bool>(m));
            stack<pair<int, int>> stack;
            stack.push({i, j});

            while (!stack.empty()) {
                auto [row, col] = stack.top(); stack.pop();

                if (row < 0 || col < 0 || row >= n || col >= m || seen[row][col] || grid[row][col] == '#') continue;
                seen[row][col] = true;
                if (good[row][col]) {
                    seen[n-1][m-1] = true;
                    break;
                }
                good[row][col] = true;

                if (row == n-1 && col == m-1) break;

                stack.push({row+1, col});
                stack.push({row-1, col});
                stack.push({row, col+1});
                stack.push({row, col-1});
            }

            if (!seen[n-1][m-1]) {
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}