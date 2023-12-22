#include <bits/stdc++.h>

using namespace std;

int main() {
    // ifstream fin("input.txt");
    string line;
    vector<vector<char>> grid;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, -1}, {-1, 1}, {-1, -1}, {1, 1}};

    while (getline(cin, line)) {
        vector<char> row;
        for (char c : line) {
            row.push_back(c);
        }
        grid.push_back(row);
    }
    int ans = 0;
    for (int i = 0; i < int(grid.size()); i++) {
        for (int j = 0; j < int(grid[0].size()); j++) {
            bool symbol = false;
            string num = "";

            while (int(grid[i][j]) - int('0') < 10 && int(grid[i][j]) - int('0') >= 0 && j < int(grid[0].size())) {
                num += grid[i][j];
                j++;
            }

            for (int k = j-1; k >= j-int(num.size()); k--) {
                for (vector<int> dir : directions) {
                    int nRow = i + dir[0];
                    int nCol = k + dir[1];

                    if (nRow >= 0 && nRow < int(grid.size()) && nCol >= 0 && nCol < int(grid[0].size())) {
                        if (grid[nRow][nCol] - int('0') > 10 || grid[nRow][nCol] - int('0') < 0) {
                            if (grid[nRow][nCol] != '.') {
                                if (num != "") ans += stoi(num);
                                symbol = true;
                                break;
                            }
                        }
                    }
                }
                if (symbol) {
                    break;
                }
            }

        }
    }

    cout << ans << "\n";
}