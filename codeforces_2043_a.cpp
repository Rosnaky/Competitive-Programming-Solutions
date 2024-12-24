#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void solve() {

    ll n; cin >> n;

    ll ans = 1;

    while (n > 3) {
        ans *= 2;
        n /= 4;
    }

    cout << ans << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}