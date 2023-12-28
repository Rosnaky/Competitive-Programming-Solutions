#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int sRow, sCol;
    vector<vector<int>> graph(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '*') graph[i][j] = 1;
            if (c == 'X') sRow = i, sCol = j;
        }
    }

    vector<pair<vector<int>, string>> dirs = {{{0, 1}, "R"}, {{1, 0}, "D"}, {{0, -1}, "L"}, {{-1, 0}, "U"}};

    priority_queue<pair<string, vector<int>>, vector<pair<string, vector<int>>>, greater<pair<string, vector<int>>>> queue;
    queue.push({"", {sRow, sCol}});

    while (!queue.empty()) {
        string s = queue.top().first;
        int row = queue.top().second[0], col = queue.top().second[1];
        queue.pop();

        if (s.size() > k) continue;
        if (s.size() == k && row == sRow && col == sCol) {
            cout << s;
            return 0;
        }

        for (auto dir : dirs) {
            int nRow = row+dir.first[0], nCol = col+dir.first[1];
            string tok = dir.second;

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && graph[nRow][nCol] == 0) {
                string temp = s+tok;
                queue.push({temp, {nRow, nCol}});
            }
        }
    }

    cout << "IMPOSSIBLE";
    
}