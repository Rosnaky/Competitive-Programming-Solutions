#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("pails.in", "r", stdin); freopen("pails.out", "w", stdout);

    int x, y, m; cin >> x >> y >> m;

    int ans = 0;

    for (int i = 0; i <= int(m/x); i++) {
        for (int j = 0; j <= int(m/y); j++) {
            int temp = i*x + j*y;
            if (temp > m) continue;
            ans = max(ans, temp);
        }
    }
    cout << ans;
}