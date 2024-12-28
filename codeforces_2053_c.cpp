#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll re(int l, int r, int k) {
    if (l > r) return 0;
    // if (!k) return 0;
    if (r-l+1 < k) return 0;

    int m = (l+r)/2;

    if ((r-l+1)%2) {
        return m + re(l, m-1, k) + re(m+1, r, k);
    }
    
    return re(l, m, k) + re(m+1, r, k);

}

void solve() {
    int n, k; cin >> n >> k;

    ll ans = re(1, n, k);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}