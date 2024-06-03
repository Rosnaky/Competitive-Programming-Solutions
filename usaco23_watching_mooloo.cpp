#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, k; cin >> n >> k;

    vector<ll> days(n);
    for (ll & i : days) cin >> i;

    ll ans = k+1;

    for (int i = 1; i < n; i++) {
        ans += min(k+1, days[i]-days[i-1]);
    }

    cout << ans;
}