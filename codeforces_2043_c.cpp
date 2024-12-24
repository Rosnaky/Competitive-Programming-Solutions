#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

void solve() {

    ll n; cin >> n;
    vector<ll> a(n);
    for (ll &i : a) cin >> i;

    ll ind = -1;
    for (ll i = 0; i < n; i++) {
        if (a[i] != 1 && a[i] != -1) {
            ind = i;
            break;
        }
    }
    ll curr = 0, mi = 0, ma = 0;
    ll prev = 0;

    
    
    // cout << mi << " " << ma << '\n';

    map<ll, bool> seen;
    for (ll i = mi; i <= ma; i++) {
        seen[i] = 1;
    }

    curr = 0, mi = 0, ma = 0;
    for (int i = 0; i < ind; i++) {
        curr += a[i];
        mi = min(curr, mi);
        ma = max(curr, ma);
    }
    for (ll i = mi; i <= ma; i++) {
        seen[i] = 1;
    }

    

    curr = 0, mi = 0, ma = 0;
    for (int i = ind+1; i < n; i++) {
        curr += a[i];
        mi = min(curr, mi);
        ma = max(curr, ma);
    }

    for (ll i = mi; i <= ma; i++) {
        seen[i] = 1;
    }

    map<ll, bool> cpy = seen;
    if (ind != -1) {
        for (auto &p : cpy) {
            seen[p.first + a[ind]] = 1;
        }
    }


    curr = 0, mi = 0, ma = 0, prev = 0;
    for (ll i = ind+1; i < n; i++) {
        if (a[i] != prev) {
            curr = 0;
            prev = a[i];
        }
        curr += a[i];
        mi = min(curr, mi);
        ma = max(curr, ma);
    }
curr = 0, mi = 0, ma = 0, prev = 0;
    for (ll i = 0; i < ind; i++) {
        if (a[i] != prev) {
            curr = 0;
            prev = a[i];
        }
        curr += a[i];
        mi = min(curr, mi);
        ma = max(curr, ma);
    }
    // cout << mi << " " << ma << '\n';
    for (ll i = mi; i <= ma; i++) {
        seen[i] = 1;
    }

    cout << seen.size() << '\n';
    for (auto &p : seen) {
        cout << p.first << " ";
    
    }
    cout << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);


    ll t; cin >> t;
    while (t--) solve();
    
}