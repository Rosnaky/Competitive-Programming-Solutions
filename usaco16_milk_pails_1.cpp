#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    freopen("pails.in", "r", stdin); freopen("pails.out", "w", stdout);

    int x, y, m; cin >> x >> y >> m;

    int ans = 0;

    for (int i = 0; i <= m/x; i++) {
        int curr = i * x + y*((m-i*x)/y);
        ans = max(ans, curr);
    }

    cout << ans << '\n';
}