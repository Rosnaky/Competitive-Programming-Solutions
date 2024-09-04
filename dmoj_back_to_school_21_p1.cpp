#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, k; cin >> n >> m >> k;

    vector<vector<char>> grid(n, vector<char>(m));

    for (vector<char>& v: grid) {
        string s; cin >> s;
        for (int i = 0; i < m; i++) {
            v[i] = s[i];
        }
    }

    vector<vector<char>> ans(n, vector<char>(m, '.'));

    for (int i = 0; i < n; i++) {
        int curr = 0;
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'B') {
                if (curr) ans[i][j] = 'N';
                else ans[i][j] = 'Y';
            }
            if (grid[i][j] == 'A') curr = k;
            else if (curr) curr--;
        }
    }
    for (int i = 0; i < n; i++) {
        int curr = 0;
        for (int j = m-1; j >= 0; j--) {
            if (grid[i][j] == 'A') {
                if (curr) ans[i][j] = 'N';
                else ans[i][j] = 'Y';
            }
            if (grid[i][j] == 'B') curr = k;
            else if (curr) curr--;
        }
    }

    for (vector<char>& v : ans) {
        for (char c : v) cout << c;
        cout << '\n';
    }
}