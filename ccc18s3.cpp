#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
#define BIG int(1e9)


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    int sRow = -1, sCol = -1;
    for (int i = 0; i < n; i++) {
        string temp; cin >> temp;
        for (int j = 0; j < m; j++) {
            grid[i][j] = temp[j];
            if (grid[i][j] == 'S') sRow = i, sCol = j;
        }
    }
    
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'C') {
                for (int d = 0; d < 4; d++) {
                    for (int k = 1; 1; k++) {
                        int a = i+dir[d][0]*k, b = j+dir[d][1]*k;
                        if (a >= 0 && a < n && b >= 0 && b < m && grid[a][b] != 'W') {
                            if (grid[a][b] != '.') continue;
                            grid[a][b] = '/';
                        }
                        else {
                            break;
                        }
                    }
                }
            }
        }
    }

    // for (auto row : grid) {
    //     for (auto col : row) cout << col;
    //     cout << endl;
    // }

    
    
    vector<vector<int>> dist(n, vector<int>(m, BIG));
    dist[sRow][sCol] = 0;
    queue<vector<int>> queue;
    queue.push({sRow, sCol});

    while (!queue.empty()) {
        int row = queue.front()[0], col = queue.front()[1];
        // cout << row << " " << col << endl;
        queue.pop();
        int d = -1;
        if (grid[row][col] == 'U') d = 0;
        else if (grid[row][col] == 'R') d = 1;
        else if (grid[row][col] == 'D') d = 2;
        else if (grid[row][col] == 'L') d = 3;
        else d = -1;

        for (int i = 0; i < 4; i++) {
            if (d != -1 && d != i) continue;
            int nRow = row+dir[i][0], nCol = col + dir[i][1];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] != 'W' && grid[nRow][nCol] != 'C' && grid[nRow][nCol] != '/') {
                if (dist[nRow][nCol] > dist[row][col]+(d==-1)) {
                    dist[nRow][nCol] = dist[row][col]+(d==-1);
                    queue.push({nRow, nCol});
                }
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '/') cout << "-1" << "\n";
            else if (grid[i][j] == '.') {
                if (dist[i][j] == BIG) cout << "-1" << "\n";
                else cout << dist[i][j] << "\n";
            }
        }
    }
}