#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void backtrack(int row, int col, int& n, vector<int>& curr, vector<vector<int>>& perms, vector<vector<bool>>& seen) {
    if (curr.size() == n*2) {
        perms.push_back(curr);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (seen[0][i]) continue;
        seen[0][i] = true;
        curr.push_back(i);
        for (int j = 0; j < n; j++) {
            if (seen[1][j]) continue;
            seen[1][j] = true;
            curr.push_back(j);
            backtrack(i, j, n, curr, perms, seen);
            curr.pop_back();
            seen[1][j] = false;
        }
        seen[0][i] = false;
        curr.pop_back();
    }
}

void solve() {
    
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    for (vector<int>& row : grid) {
        for (int& col : row) {
            cin >> col;
        }
    }

    vector<vector<int>> perms;
    vector<int> curr = {};
    vector<vector<bool>> seen(2, vector<bool>(n));
    backtrack(0, 0, n, curr, perms, seen);

    int ans = 1e9;
    for (vector<int>& curr : perms) {
        int temp = 0;
        for (int i = 0; i < curr.size()-1; i+=2) {
            temp += grid[curr[i]][curr[i+1]];
            // cout << curr[i] << curr[i+1];
        }
        // cout << endl;
        ans = min(ans, temp);
    }
    cout << ans << "\n";
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}