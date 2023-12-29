#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<vector<int>> prefix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> prefix[i][j];
            if (i > 0) prefix[i][j] += prefix[i-1][j];
            if (j > 0) prefix[i][j] += prefix[i][j-1];
            if (i > 0 && j > 0) prefix[i][j] -= prefix[i-1][j-1];
        }
    }

    int ans = -1e9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = i; k < n; k++) {
                for (int l = j; l < n; l++) {
                    int temp = prefix[k][l];
                    if (i > 0) temp -= prefix[i-1][l];
                    if (j > 0) temp -= prefix[k][j-1];
                    if (i > 0 && j > 0) temp += prefix[i-1][j-1];

                    ans = max(ans, temp);
                }
            }
        }
    }

    cout << ans;
}