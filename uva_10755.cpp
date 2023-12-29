#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    vector<vector<vector<ll>>> prefix(a, vector<vector<ll>>(b, vector<ll>(c)));
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            for (int k = 0; k < c; k++) {
                cin >> prefix[i][j][k];
                // if (i > 0) prefix[i][j][k] += prefix[i-1][j][k];
                // if (j > 0) prefix[i][j][k] += prefix[i][j-1][k];
                // if (k > 0) prefix[i][j][k] += prefix[i][j][k-1];
                if (i > 0 && j > 0) prefix[i][j][k] += prefix[i-1][j-1][k];
                if (i > 0 && k > 0) prefix[i][j][k] += prefix[i-1][j][k-1];
                if (k > 0 && j > 0) prefix[i][j][k] += prefix[i][j-1][k-1];
                if (i > 0 && j > 0 && k > 0) prefix[i][j][k] -= prefix[i-1][j-1][k-1];
            }
        }
    }


    int ans = -1e9;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            for (int k = 0; k < c; k++) {
                for (int l = i; l < a; l++) {
                    for (int m = j; m < b; m++) {
                        for (int n = k; n < c; n++) {
                            int temp = prefix[l][m][n];
                            // if (i > 0) temp -= prefix[i-1][m][n];
                            // if (j > 0) temp -= prefix[l][j-1][n];
                            // if (k > 0) temp -= prefix[l][m][k-1];
                            if (i > 0 && j > 0) temp -= prefix[i-1][j-1][n];
                            if (i > 0 && k > 0) temp -= prefix[i-1][m][k-1];
                            if (k > 0 && j > 0) temp -= prefix[l][j-1][k-1];
                            if (i > 0 && j > 0 && k > 0) temp += prefix[i-1][j-1][k-1];

                            ans = max(ans, temp);
                        }
                    }
                }
            }
        }
    }

    cout << ans << "\n" << "\n";
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}