#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define BIG int(1e9)
typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<vector<bool>> grid(n, vector<bool>(n, 1));

    int k; cin >> k;
    for (ll i = 0; i < k; i++) {
        ll x, y, x1, y1;
        cin >> x >> y >> x1 >> y1;
        x--; y--; x1--; y1--;
        for (ll k = min(x, x1); k <= max(x1, x); k++) {
            for (ll l = min(y, y1); l <= max(y1, y); l++) {
                grid[k][l] = false;
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (grid[i][j] == -BIG) continue;
    //         if (i > 0 && grid[i-1][j] != -BIG) grid[i][j] += grid[i-1][j];
    //         if (j > 0 && grid[i][j-1] != -BIG) grid[i][j] += grid[i][j-1];
    //         if (i > 0 && j > 0 && grid[i-1][j-1] != -BIG) grid[i][j] -= grid[i-1][j-1];
    //     }
    // }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         grid[i][j] = n*i+j;
    //     }
    // }

    // for (auto row : grid) {
    //     for (auto col : row) cout << col << " ";
    //     cout << endl;
    // }

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (!grid[i][j]) continue;
            
            ll rowL = n, colL = n;
            bool valid = true;
            for (ll k = i; k < rowL; k++) {
                for (ll l = j; l < colL; l++) {
                    if (!grid[k][l]) {
                        if (l == j) {
                            rowL = k;
                            colL = l;
                            valid = false;
                            break;
                        }
                        else {
                            colL = l;
                            break;
                        }
                    }
                    ans = max(ans, ll(k-i+1)*ll(l-j+1));
                }
                if (!valid) break;
            }
        }
    }

    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--) solve();
}

