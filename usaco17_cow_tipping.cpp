#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);

    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < n; j++) {
            grid[i][j] = temp[j]-'0';
        }
    }

    int ans = 0;

    for (int i = n-1; i>= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            if (grid[i][j] == 1) {
                ans++;
                for (int a = 0; a <= i; a++) {
                    for (int b = 0; b <= j; b++) {
                        grid[a][b] = !grid[a][b];
                    }
                }
            }
        }
    }

    cout << ans;


}