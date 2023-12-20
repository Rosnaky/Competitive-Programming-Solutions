#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int w;
    cin >> w;

    vector<vector<int>> grid(2, vector<int>(w, 0));

    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < w; col++) {
            cin >> grid[row][col];
        }
    }


    int ans = 0;

    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < w; col++) {
            int curr = grid[row][col];

            if (curr == 1) {
                ans += 3;
            }
            if (row == 0 && col%2 == 0 && grid[1][col] == 1) {
                ans -= 1;
            }
            if (col != w-1 && grid[row][col+1] == 1) {
                ans -= 1;
            }
        }
    }
    cout << ans;
}
