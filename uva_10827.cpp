#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void solve(){
    int n; cin >> n;

    vector<vector<int>> prefix(2*n, vector<int>(2*n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> prefix[i][j];

            if (i > 0) prefix[i][j] += prefix[i-1][j];
            if (j > 0) prefix[i][j] += prefix[i][j-1];
            if (i > 0 && j > 0) prefix[i][j] -= prefix[i-1][j-1];

            prefix[i+n][j] = prefix[i][j];
            prefix[i+n][j+n] = prefix[i][j];
            prefix[i][j+n] = prefix[i][j];
        }
    }

    

    int ans = -1e9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = i; k < i+n; k++) {
                for (int l = j; l < i+n; l++) {
                    int temp = prefix[k][l];
                    if (i > 0) temp -= prefix[i-1][l];
                    if (j > 0) temp -= prefix[k][j-1];
                    if (i > 0 && j > 0) temp += prefix[i-1][j-1];

                    if (l >= n) {
                        temp += prefix[k][n-1];
                        if (n>=2) temp -= prefix[k][n-2];
                        if (k > 0) temp -= prefix[k-1][n-1];
                        if (n>= 2 && k > 0) temp += prefix[k-1][n-2];
                    }

                    ans = max(ans, temp);
                }
            }
        }
    }

    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}