#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    
    vector<vector<char>> grid(n, vector<char>(m));

    for (auto &a : grid) {
        string s; cin >> s;
        for (int i = 0; i < m; i++) {
            a[i] = s[i];
        }
    }

    vector<vector<bool>> seen(n, vector<bool>(m));
    queue<pair<int, int>> queue;
    int r, c; cin >> r >> c;
    queue.push({r, c});

    long long ans = 0;
    vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    while (!queue.empty()) {
        auto [row, col] = queue.front(); queue.pop();

        if (seen[row][col]) continue;
        seen[row][col] = true;
        if (grid[row][col] == '*') continue;

        ans += grid[row][col] == 'L' ? 10 : grid[row][col] == 'M' ? 5 : 1;

        for (auto d : dir) {
            int nRow = row+d.first, nCol = col+d.second;
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m) {
                queue.push({nRow, nCol});
            }
        }
    }

    cout << ans;
}