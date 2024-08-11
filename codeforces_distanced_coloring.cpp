#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void solve() {
    int n, m, k; cin >> n >> m >> k;

    int ans = 0, cells = n*m;

    if (n <= k && m <= k) {
        cout << cells << '\n';
        return;
    }

    int remaining = cells;
    if (n-k > 0) {
        remaining -= max(0, n-k)*m;
        remaining -= max(0, m-k)*(k);
    }
    else if (m-k > 0) {
        remaining -= max(0, m-k)*n;
        remaining -= max(0, n-k)*(k);
    }

    ans += remaining;
    cout << ans << '\n';

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

