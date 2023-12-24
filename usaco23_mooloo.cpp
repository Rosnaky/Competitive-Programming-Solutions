#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;

    vector<ll> days;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        days.push_back(x);
    }

    ll ans = k+1;

    for (int i = 1; i < n; i++) {
        ans += min(k+1, days[i]-days[i-1]);
    }

    cout << ans;
}