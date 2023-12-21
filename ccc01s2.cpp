#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    for (int x = 0; x < n; x++) {
        int curr, end;
        cin >> curr >> end;

        vector<vector<int>> grid = {{curr}};

        int moves = 0;

        while (curr != end) {
            curr += 1;

            if (moves % 2 == 0) {
                if (moves % 4 == 0) {
                    for (int i = 0; i < int(grid.size());i++, curr++) grid.push_back({curr});
                }
                else {
                    for (int i = 0; i < int(grid.size());i++, curr++) grid.emplace(grid.begin(), curr);
                }
            }
            else {
                if ((moves-1) % 4 == 0) {
                    for (int i = 0; i < int(grid[0].size());i++, curr++) grid[grid.size()-1].push_back(curr);
                }
                else {
                    for (int i = 0; i < int(grid[0].size());i++, curr++) grid[0].emplace(grid[0].begin(), curr);
                }
            }
            moves += 1;
        }

        for (auto row : grid) {
            for (auto col : row) {
                cout << col << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}