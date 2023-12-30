#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

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

    priority_queue<pair<int, vector<int>>> queue;
    queue.push({0, {0, 0}});
    vector<vector<int>> dist(r, vector<int>(c, BIG));
    dist[0][0] = 0;
    vector<vector<bool>> seen(r, vector<bool>(c));

    vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    while (!queue.empty()) {
        int row = queue.top().second[0], col = queue.top().second[1];
        queue.pop();

        if (seen[row][col]) continue;
        seen[row][col] = true;

        for (vector<int>& d : dir) {
            int nRow = row+d[0], nCol = col+d[1];
            if (nRow >= 0 && nRow < r && nCol >= 0 && nCol < c) {
                int diff = grid[row][col] != grid[nRow][nCol];

                if (dist[nRow][nCol] > dist[row][col]+diff) {
                    dist[nRow][nCol] = dist[row][col]+diff;
                    queue.push({-dist[nRow][nCol], {nRow, nCol}});
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
    while(t--) solve();
}