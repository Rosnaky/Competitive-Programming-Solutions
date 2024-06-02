#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);


    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);

    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            grid[i][j] = s[j]-'0';
        }
    }


    vector<bool> covers(10);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            covers[grid[i][j]] = 1;
        }
    }


    for (int i = 1; i <= 9; i++) {
        int left=-1, top=-1, right=-1, bottom=-1;

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (left!=-1 && top!=-1 && right!=-1 && bottom!=-1) break;
    

                if (left==-1 && grid[k][j] == i) left = j;
                if (top==-1 && grid[j][k] == i) top = j;
                if (right==-1 && grid[n-1-k][n-1-j] == i) right = n-1-j;
                if (bottom==-1 && grid[n-1-j][n-1-k] == i) bottom = n-1-j; 
            }
        }
        // cout << i << ": " << left << " " << top << " " << right << " " << bottom << "\n";
        if (left == -1) continue;
        
        for (int j = top; j <= bottom; j++) {
            for (int k = left; k <= right; k++) {
                if (grid[j][k] != i) {
                    covers[grid[j][k]] = 0;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= 9; i++) {
        ans += covers[i];
    }

    cout << ans;

}