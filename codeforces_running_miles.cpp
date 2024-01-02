#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<ll> prefix(n+1);
    vector<ll> suffix(n+2);
    vector<ll> nums(n+1);
    suffix[n+1] = -1e9;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    for (int i = 1; i <= n; i++) {
        prefix[i] = max(prefix[i-1],nums[i]+i);
    }
    for (int i = n; i>=1;i--) {
        suffix[i] = max(suffix[i+1], nums[i]-i);
    }

    ll ans = 0;
    for (int i = 2; i < n; i++) {
        ans = max(ans, nums[i]+prefix[i-1]+suffix[i+1]);
    }

    cout << ans << "\n";
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);


    int t; cin >> t;
    while (t--) solve();
}