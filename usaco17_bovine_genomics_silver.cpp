#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("cownomics.in", "r", stdin); freopen("cownomics.out", "w", stdout);

    int n, m; cin >> n >> m;

    vector<string> spot(n), plain(n);
    for (int i = 0; i < n; i++) {
        cin >> spot[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> plain[i];
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i+1; j < m; j++) {
            for (int k = j+1; k < m; k++) {

                for (int l = 0; l < n; l++) {
                    bool valid = true;
                    for (int a = 0; a < n; a++) {
                        if (plain[a][i] == spot[l][i] && plain[a][j] == spot[l][j] && plain[a][k] == spot[l][k]) {
                            valid = false;
                            break;
                        }
                    }

                    if (valid) {
                        cout << i << " " << j << " " << k << endl;
                        ans++;
                        break;
                    }

                }

            }
        }
    }
    cout << ans;
}