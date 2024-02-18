#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    for (vector<int>& row : grid) {
        for (int& col : row) {
            cin >> col;
        }
    }


    if (grid[0][0] < grid[0][1] && grid[0][0] < grid[1][0]) {
        for (auto row : grid) {
            for (int col : row) {
                cout << col << " ";
            }
            cout << endl;
        }
        return 0;
    }

    if (grid[0][0] < grid[0][1] && grid[0][0] > grid[1][0]) {
        for (int j = 0; j < n; j++) {
            for (int i = n-1; i >= 0; i--) {
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }
        return 0;
    }

    if (grid[0][0] > grid[0][1] && grid[0][0] < grid[1][0]) {
        for (int j = n-1; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        return 0;
    }

    if (grid[0][0] > grid[0][1] && grid[0][0] > grid[1][0]) {
        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                cout << grid[j][i] << " ";
            }
            cout << endl;
        }
        return 0;
    }
}