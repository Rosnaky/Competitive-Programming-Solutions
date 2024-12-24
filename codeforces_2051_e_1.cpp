#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
ll bs(vector<ll>& arr, ll target) {
    
    ll lo = 0, hi = arr.size()-1;
    ll ans = -1;
    while (lo <= hi) {
        ll mid = lo + (hi-lo)/2;

        if (arr[mid] == target) {
            ans = mid;
            hi = mid-1;
        }
        else if (arr[mid] < target) {
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }

    if (ans == -1) return lo;
    return ans;
}

void solve() {

    ll n, k; cin >> n >> k;

    vector<ll> a(n), b(n);
    for (ll &i : a) cin >> i;
    for (ll &i : b) cin >> i;

    // possible prices
    vector<ll> prices;
    for (ll i : a) prices.push_back(i);
    for (ll i : b) prices.push_back(i);

    sort(prices.begin(), prices.end());

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = 0;

    for (ll p : prices) {
        ll notBuy = bs(b, p);
        // check how many will not buy
        ll buy = n-notBuy;
        // bad review
        ll badReview = bs(a, p);

        // cout << p << " " << buy << " " << notBuy << " " << badReview << '\n'; 

        if (badReview-notBuy > k) continue;

        ans = max(ans, buy*p);
    }

    cout << ans << '\n';

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;
    while (t--) solve();
}