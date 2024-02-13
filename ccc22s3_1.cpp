#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, m, k; cin >> n >> m >> k;

    vector<ll> ans;
    
    for (ll i = 0; i < n; i++) {
        ll rem = n-i-1;
        ll curr = min(k-rem, m);
        if (curr <= 0) break;
        ll val;
        if (curr > i) {
            val=min(m, i+1);
            curr = val;
        }
        else val = ans[i-curr];

        ans.push_back(val);
        k -= curr;
    }

    if (k == 0 && ans.size() == n) {
        for (auto i : ans) cout << i << " ";
        return 0;
    }
    cout << -1;
}