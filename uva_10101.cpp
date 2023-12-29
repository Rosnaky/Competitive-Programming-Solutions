#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void solve(int n, int m) {
    
    vector<vector<int>> grid(n, vector<int>(m, 1));
    for (int i = 0; i < n; i++) {
        string temp; cin >> temp;
        for (int j = 0; j < m; j++) {
            grid[i][j] = temp[j]-'0';
            // cout << grid[i][j] << " ";
        }
        // cout << endl;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != 1) continue;
            for (int height = 1; height < n-i+1; height++) {
                for (int width = 1; width < m-j+1; width++) {
                    bool valid = true;
                    for (int k = i; k < height+i; k++) {
                        for (int l = j; l < width+j; l++) {
                            if (grid[k][l] != 1) {
                                valid = false;
                                break;
                            }
                        }

                        if (!valid) break;
                    }
                    
                    if (valid) ans++;
                }
            }
        }
    }

    cout << ans << "\n";

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;
    while (n!=0) {
        cin >> m;
        solve(n, m);
        cin >> n;
    }
}