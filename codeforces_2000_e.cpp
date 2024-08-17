#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

void solve() {

    int n, m, k; cin >> n >> m >> k;
    int w; cin >> w;

    vector<int> a(w);
    vector<vector<int>> grid(n, vector<int>(m));

    for (int &i : a) cin >> i;

    for (int i = 0; i <= n-k; i++) {
        for (int j = 0; j <= m-k; j++) {
            for (int l = 0; l < k; l++) {
                for (int o = 0; o < k; o++) {
                    grid[i+l][j+o]++;
                }
            }
        }
    }

    sort(a.rbegin(), a.rend());
    vector<int> linear;

    for (auto& v : grid) {
        for (int i : v) {
            linear.push_back(i);
        }
    }

    sort(linear.rbegin(), linear.rend());
    ll ans = 0;
    
    for (int i = 0; i < min(w, n*m); i++) {
        ans += (ll) linear[i] * a[i];
    }

    cout << ans << '\n';

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}