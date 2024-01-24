#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;

void solve() {
    double n, b, h; cin >> n >> b >> h;

    double ans = 0;

    double prev = -1e9;
    for (int i = 0; i < n; i++) {
        double y; cin >> y;

        ans += b*h/2;

        if (prev != 1e9 && y-prev < h) {
            ans -= (h-y+prev)*((b/h)*(y-prev))/2;
        }

        prev = y;
    }
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(numeric_limits<double>::max_digits10);

    int t; cin >> t;
    while (t--) solve();
}