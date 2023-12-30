#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>

using namespace std;
#define BIG int(1e9)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;


    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string temp; cin >> temp;
        for (int j = 0; j < m; j++) {
            if(temp[j] == '#') grid[i][j] = 1;
        }
    }


    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;

    deque<vector<int>> queue;
    queue.push_front({x1, y1});
    vector<vector<int>> dist(n, vector<int>(m, BIG));
    dist[x1][y1] = 0;
    // vector<vector<bool>> seen(n, vector<bool>(m));

    vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    while (!queue.empty()) {
        int row = queue.front()[0], col = queue.front()[1];
        queue.pop_front();

        // if (seen[row][col]) continue;
        // seen[row][col] = true;

        for (vector<int>& d : dir) {
            for (int i = 1; i <= k; i++) {
                int nRow = row+d[0]*i, nCol = col+d[1]*i;
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m) {
                    if (!grid[nRow][nCol]) {
                        if (dist[nRow][nCol] > dist[row][col]+1) {
                            dist[nRow][nCol] = dist[row][col]+1;
                            queue.push_front({nRow, nCol});
                        }
                    }
                    else break;
                }
                else break;
            }
        }
    }
    if (dist[x2][y2] == BIG) cout << -1;
    else cout << dist[x2][y2];
}