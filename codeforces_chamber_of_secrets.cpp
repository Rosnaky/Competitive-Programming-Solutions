#include <vector>
#include <algorithm>
#include <iostream>
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
    for (int i = 0; i < n; i++) {
        string temp; cin >> temp;
        for (int j = 0; j < m; j++) {
            grid[i][j] = temp[j] == '#';
        }
    }

    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};


    vector<vector<int>> dist(n, vector<int>(m, BIG));
    dist[n-1][m-1] = 0;
    deque<vector<int>> queue;
    queue.push_front({n-1, m-1, 3, 0});

    while (!queue.empty()) {
        int row = queue.front()[0], col = queue.front()[1], d = queue.front()[2], curr = queue.front()[3];
        queue.pop_front();

        for (int i = 0; i <= 3; i++) {
            if (!grid[row][col] && i!=d) continue;
            int nRow = row+dir[i][0], nCol = col + dir[i][1];
            

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m) {
                if (nRow == 0 && nCol == 0 && i != 3) continue;
                if (dist[nRow][nCol] > curr+(d != i)) {
                    dist[nRow][nCol] = curr+(d!=i);

                    if (d == i) {
                        queue.push_front({nRow, nCol, i, dist[nRow][nCol]});
                    }
                    else {
                        queue.push_back({nRow, nCol, i, dist[nRow][nCol]});
                    }
                }
            }
        }
    }
    
    if (dist[0][0] == BIG) cout << -1;
    else cout << dist[0][0];
}