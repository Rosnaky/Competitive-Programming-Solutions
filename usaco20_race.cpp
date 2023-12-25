#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);

    int k, n;
    cin >> k >> n;

    for (int a = 0; a < n; a++) {
        int x;
        cin >> x;

        int ans = 0;
        int r = k;
        int v = 1;

        while (r > 0 && v < x) {
            ans++;
            r-=v;
            v++;
        }

        bool first = true;

        while (r > 0) {
            ans++;
            r-=v;
            if (first) {
                first = false;
            }
            else {
                v++;
                first = true;
            }
        }

        cout << ans << "\n";
    }
}