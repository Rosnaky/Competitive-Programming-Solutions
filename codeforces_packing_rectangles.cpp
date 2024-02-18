#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

ll w, h, n;
bool valid(ll x) {
    ll cnt = 0;
    ll nm1 = (x/w);
    ll nm2 = (x/h);
    cnt = nm1*nm2;

    return cnt >= n;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> w >> h >> n;

    ll l = 0, r = 1;
    while (!valid(r)) r *= 2;

    while (l + 1 < r) {
        ll mid = l+(r-1)/2;

        if (valid(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    cout << r;
    
}