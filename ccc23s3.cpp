
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n, m, r, c;
    cin >> n >> m >> r >> c;


    vector<vector<char>> grid(n, vector<char>(m, 'a'));

    if (r == n) {
        if (c%2 != 0 && (m%2 == 0 || m <= 2)) {
            cout << "IMPOSSIBLE";
            return 0;
        }
        else {
            for (int i = 0; i < (m-c)/2; i++) {
                grid[0][i] = 'b';
                grid[0][m-i-1] = 'b';
            }
        }
        if (m%2 != 0 && c%2 == 0) {
            grid[0][m/2] = 'b';
        }

    }
    else if (c == m) {
        if (r%2 != 0 && (n%2 == 0 || n <= 2)) {
            cout << "IMPOSSIBLE";
            return 0;
        }
        else {
            for (int i = 0; i < (n-r)/2; i++) {
                grid[i][0] = 'b';
                grid[n-i-1][0] = 'b';
            }
        }
        if (n%2 != 0 && r%2 == 0) {
            grid[n/2][0] = 'b';
        }
    }
    else {
        for (int i = r; i < n; i++) {
            grid[i][m-1] += 1;
        }


        for (int i = c; i < m; i++) {
            grid[n-1][i] += 1;
        }
    }
    

    

    

    for (auto row : grid) {
        for (auto col : row) {
            cout << col;
        }
        cout << endl;
    }

    
    
}