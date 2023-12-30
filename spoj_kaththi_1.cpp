#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
#define BIG int(1e9)

void solve() {
    int r, c;
    cin >> r >> c;

    vector<vector<char>> grid(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
        string temp;
        cin >> temp;

        for (int j = 0; j < c; j++) {
            grid[i][j] = temp[j];
        }
    }

    deque<vector<int>> queue;
    queue.push_front({0, 0});
    vector<vector<int>> dist(r, vector<int>(c, BIG));
    dist[0][0] = 0;
    // vector<vector<bool>> seen(r, vector<bool>(c));

    vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    while (!queue.empty()) {
        int row = queue.front()[0], col = queue.front()[1];
        queue.pop_front();
        for (vector<int>& d : dir) {
            int nRow = row+d[0], nCol = col+d[1];
            if (nRow >= 0 && nRow < r && nCol >= 0 && nCol < c) {
                int diff = grid[row][col] != grid[nRow][nCol];

                if (dist[nRow][nCol] > dist[row][col]+diff) {
                    dist[nRow][nCol] = dist[row][col]+diff;
                    if (diff) {
                        queue.push_back({nRow, nCol});
                    }
                    else {
                        queue.push_front({nRow, nCol});
                    }
                }
            }
        }
    }
    cout << dist[r-1][c-1] << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}