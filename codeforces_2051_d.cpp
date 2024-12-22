#include <algorithm>
#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

void solve() {

    ll n, x, y; cin >> n >> x >> y;

    vector<ll> a(n);
    for (ll &i : a) cin >> i;

    ll curr = 0;
    for (ll i : a) {
        curr += i;
    }

    sort(a.begin(), a.end());
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        if (curr - a[i] - x < a[0] && curr - a[i] - y < a[0]) continue;
        if (curr - a[i] - x > a[n-1] && curr - a[i] - y > a[n-1]) continue;

        ll target = curr - a[i] - x;
        ll lo = 0, hi = n-1;
        ll lb = -1;
        while (lo <= hi) {
            ll mid = lo + (hi - lo)/2;
            // cout << lo << " " << hi << " " << mid << '\n';
            if (a[mid] == target) {
                lb = mid;
                lo = mid+1;
            }
            else if (a[mid] < target) {
                lo = mid + 1;
            }
            else if (a[mid] > target) hi = mid-1;
        }

        if (lb == -1) lb = hi;

        // cout << lo << " " << hi << " " << lb << endl;
        
        target = curr - a[i] - y;
        
        lo = 0, hi = n-1;
        ll ub = -1;
        while (lo <= hi) {
            ll mid = lo + (hi - lo)/2;
            if (a[mid] == target) {
                ub = mid;
                hi = mid-1;
            }
            else if (a[mid] < target) {
                lo = mid + 1;
            }
            else if (a[mid] > target) hi = mid-1;
        }

        if (ub == -1) ub = lo;

        // cout << lb << " " << ub << endl;
        // ans += max(ub-lb+1, lb-ub+1);
        ans += max(0LL, lb-ub+1);
        if (a[ub] <= a[i] && a[i] <= a[lb]) ans--;
    }
    // cout << ans << " " ;
    cout << ans/2 << '\n';

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;
    while (t--) solve();
}