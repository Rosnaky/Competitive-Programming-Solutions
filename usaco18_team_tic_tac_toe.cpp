#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>

using namespace std;

vector<set<set<int>>> ans(2);


void calc(int a, int b, int c) {
    if (a == b && b == c) ans[0].insert({a, b, c});
    else if (a == b || b == c || a == c) ans[1].insert({a, b, c});
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("tttt.in", "r", stdin); freopen("tttt.out", "w", stdout);

    vector<vector<char>> grid(3, vector<char>(3));
    for (int i = 0; i < 3; i++) {
        string s; cin >> s;
        for (int j = 0; j < 3; j++) {
            grid[i][j] = s[j];
        }
    }

    for (int i = 0; i < 3; i++) {
        calc(grid[i][0], grid[i][1], grid[i][2]);
        calc(grid[0][i], grid[1][i], grid[2][i]);
    }
    calc(grid[0][0], grid[1][1], grid[2][2]);
    calc(grid[2][0], grid[1][1], grid[0][2]);


    cout << ans[0].size() << "\n" << ans[1].size();
}
