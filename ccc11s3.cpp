#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;
vector<vector<vector<bool>>> grid;

bool make() {
    for (int m = 1; m <= 13; m++) {
        ll n = pow(5, m);
        grid[m] = vector<vector<bool>>(n, vector<bool>(n));

        for (int i = n-1; i >= n-(n/5); i--) {
            for (int j = n/5; j < n-(n/5); j++) {
                grid[m][i][j] = true;
            }
        }
        for (int i = n-(2*n/5); i <= n-(n/5); i--) {
            for (int j = n/5*2; j < n-(2*n/5); j++) {
                grid[m][i][j] = true;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    make();

    return 0;

    for (int i = 0; i < n; i++) {

        int m, x, y; cin >> m >> x >> y;

        if (grid[m][x][y]) {
            cout << "crystal" << "\n";
        }
        else {
            cout << "empty" << "\n";
        }

    }
}