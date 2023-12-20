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

    int i = 0;

    while (i < int(line.size())) {
        char type = line[i];
        int count = 0;
        while (line[i] == type && i != int(line.size())) {
            i++;
            count += 1;
        }

        count %= 2;
        if (type == 'H' && count == 1) {
            swap(grid[0][0], grid[1][0]);
            swap(grid[0][1], grid[1][1]);
        }
        if (type == 'V' && count == 1) {
            swap(grid[0][0], grid[0][1]);
            swap(grid[1][0], grid[1][1]);
        }
    }
    for (vector<int> row : grid) {
        for (int i : row) {
            cout << i << " ";
        }
        cout << endl;
    }
}