#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(m));

    pair<int, int> start;
    pair<int, int> end;


    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++) {
            if (temp[j] == '#') graph[i][j] = 1;
            else if (temp[j] == '.') graph[i][j] = 0;
            else if (temp[j] == 'A') start = {i, j};
            else end = {i, j};
        }
    }

    vector<vector<bool>> seen(n, vector<bool>(m, false));
    vector<pair<string, vector<int>>> dir = {{"R", {0, 1}}, {"D", {1, 0}}, {"L", {0, -1}}, {"U", {-1, 0}}};

    queue<pair<vector<int>, string>> queue;
    queue.push({{start.first, start.second, 0}, ""});
    seen[start.first][start.second] = true;

    while (!queue.empty()) {
        auto [curr, path] = queue.front();
        queue.pop();
        int row = curr[0], col = curr[1], dist = curr[2];

        if (row == end.first && col == end.second) {
            cout << "YES" << "\n";
            cout << path.size() << '\n';
            cout << path;
            return 0;
        }
        
        for (auto d : dir) {
            int nRow = d.second[0] + row, nCol = d.second[1] + col;
            string k = d.first;

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && graph[nRow][nCol] != 1 && !seen[nRow][nCol]) {
                k = path+k;
                seen[nCol][nRow] = true;
                queue.push({{nRow, nCol, dist+1}, k});
            }
        }
    }

    cout << "NO";
}