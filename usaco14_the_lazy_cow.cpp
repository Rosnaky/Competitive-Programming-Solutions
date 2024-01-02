#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("lazy.in", "r", stdin); freopen("lazy.out", "w", stdout);

    int n, k; cin >> n >> k;
    vector<vector<int>> grid(n+1, vector<int>(n+1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int temp; cin >> temp;

            grid[i][j] = grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1]+temp;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int curr = 0;

            curr += grid[i][min(n, j+k)] - grid[i][max(0, j-k-1)] - grid[i-1][min(n, j+k)] + grid[i-1][max(0, j-k-1)];
            curr += grid[min(n, i+k)][j] - grid[max(0, i-k-1)][j] - grid[min(n, i+k)][j-1] + grid[max(0, j-k-1)][j-1];
            curr += grid[min(n, i+k-1)][min(n, j+k-1)] - grid[max(0, i-k)][min(n, j+k-1)] - grid[min(n, i+k-1)][max(0, j-k)] + grid[max(0, i-k)][max(0, j-k)];
            curr -= grid[i][min(n, j+k-1)] - grid[i][max(0, j-k)] - grid[i-1][min(n, j+k-1)] + grid[i-1][max(0, j-k)];
            curr -= grid[min(n, i+k-1)][j] - grid[max(0, i-k)][j] - grid[min(n, i+k-1)][j-1] + grid[max(0, i-k)][j-1];
            ans = max(ans, curr);

            // cout << i << " " << j << " " << curr << endl;
        }
    }
    cout << ans;
}