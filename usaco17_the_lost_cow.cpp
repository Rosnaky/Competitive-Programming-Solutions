#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    int x, y; cin >> x >> y;

    int ans = 0;
    int pos = x;
    int factor = 1;

    while (true) {
        ans += abs(factor) + abs(x-pos);
        pos = x+factor;

        // cout << pos << " " << factor << endl;

        if (factor > 0 && pos >= y && y > x) {
            ans -= pos-y;
            break;
        } 
        else if (factor < 0 && pos <= y && y < x) {
            ans -= y - pos;
            break;
        }

        factor *= -2;
    }

    cout << ans;
}