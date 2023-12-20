#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string line;
    cin >> line;

    vector<vector<int>>grid = {{1, 2}, {3, 4}};

    int h = 0, v = 0;

    for (char c : line) {
        if (c == 'H') {
            h += 1;
        }
        else {
            v += 1;
        }
    }

    h%= 2;
    v%=2;

    if (h == 1) {
        swap(grid[0][0], grid[1][0]);
        swap(grid[0][1], grid[1][1]);
    }
    if (v == 1) {
        swap(grid[0][0], grid[0][1]);
        swap(grid[1][0], grid[1][1]);
    }

    for (auto row : grid) {
        for (int i : row) {
            cout << i << " ";
        }
        cout << endl;
    }
}