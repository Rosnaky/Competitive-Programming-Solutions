#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<int> a(n); for (int& i : a) cin >> i;

    int ans = 0;
    for (int mask = 0; mask < (1<<n);mask++) {
        int mi = 1e9, ma = 0, total = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1<<i)) {
                mi = min(mi, a[i]);
                ma = max(ma, a[i]);
                total += a[i];
            }
        }

        if (total >= l && total <= r && (ma-mi) >= x) {
            ans++;
        }
    }

    cout << ans;
}