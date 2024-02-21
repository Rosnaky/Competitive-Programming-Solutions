#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    
    cin >> n;

    vector<vector<double>> grid(n, vector<double>(2));
    for (int j = 0; j < 2; j++)
    for (int i = 0; i < n; i++) {
        cin >> grid[i][j];
    }

    if (grid[0][0] == grid[0][1] && grid[1][1] == grid[1][0] && grid[1][0] == grid[0][1]) {
        cout << 4;
    }
    else if (grid[0][0] == grid[1][0] && grid[1][0] == (grid[0][1] + grid[1][1])/2) cout << 3;
    else if (grid[0][1] == grid[0][0] && grid[0][0] == (grid[1][0] + grid[1][1])/2) cout << 3;
    else if (grid[0][1] == grid[1][1] && grid[1][1] == (grid[1][0] + grid[0][0])/2) cout << 3;
    else if (grid[1][0] == grid[1][1] && grid[1][1] == (grid[0][1] + grid[0][0])/2) cout << 3;
    
    else if ((grid[1][1] + grid[0][1])/2 == (grid[0][0] + grid[1][0])/2) cout << 2;
    else if ((grid[1][1] + grid[1][0])/2 == (grid[0][1] + grid[0][0])/2) cout << 2;
    
    else if ((grid[1][1] + grid[1][0] + grid[0][0])/3 == grid[0][1]) cout << 2;
    else if ((grid[1][1] + grid[0][1] + grid[0][0])/3 == grid[1][0]) cout << 2;
    else if ((grid[1][0] + grid[0][1] + grid[0][0])/3 == grid[1][1]) cout << 2;
    else if ((grid[1][0] + grid[0][1] + grid[1][1])/3 == grid[0][0]) cout << 2;

    else cout << 1;
    
}