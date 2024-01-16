#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void solve() {
    int x1 = 1e9, x2 = -1e9, y1 = 1e9, y2 = -1e9;

    for (int i = 0; i < 4; i++) {
        int x, y; cin >> x >> y;
        x1 = min(x1, x); y1 = min(y1, y);
        x2 = max(x2, x); y2 = max(y2, y);
    }

    cout << (y2-y1)*(x2-x1) << "\n";
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while(t--) solve();
}