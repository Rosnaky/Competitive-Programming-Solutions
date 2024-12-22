#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {

    int n; cin >> n;
    vector<int> a(n), b(n);

    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        a[i] -= b[i+1];
    }

    for (int i = 0; i < n; i++) {
        if (a[i] > 0) ans += a[i];
    }

    cout << ans << '\n';

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}