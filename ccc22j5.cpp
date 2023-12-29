#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define BIG int(1e9)
typedef long long ll;

void solve() {
    ll n; cin >> n;

    map<pair<int, int>, bool> trees;

    ll k; cin >> k;
    for (ll i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        trees[{x, y}] = true;
    }

    // for (auto row : grid) {
    //     for (auto col : row) cout << col << " ";
    //     cout << endl;
    // }

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (trees[{i, j}]) continue;
            
            ll rowL = n, colL = n;
            bool valid = true;
            for (ll k = i; k < rowL; k++) {
                for (ll l = j; l < colL; l++) {
                    if (trees[{k, l}]) {
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
                    if (i-k != j-l) continue;
                    ans = max(ans, ll(k-i+1));
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
    solve();
}

