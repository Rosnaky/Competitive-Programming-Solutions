#include <algorithm>
#include <iostream>
#include <vector>
#include <vector>

using namespace std;

void solve() {

    int l, r, k; cin >> l >> r >> k;
    // int ans = 0;
    // for (int i = l; i*k <= r; i++) {
        
    //     if (r >= k*i) ans++;
    // }
    int ans = max(0, r/k-l+1);

    cout << ans << '\n';

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >>t;
    while (t--) solve();
}