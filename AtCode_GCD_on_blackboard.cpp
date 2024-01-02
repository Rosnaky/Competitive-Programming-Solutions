#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if (a == 0) return b;
    return gcd(b%a, a);
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<int> nums(n+1);
    vector<int> prefix(n+1);
    vector<int> suffix(n+1);
    
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    for (int i = 2; i <= n; i++) {
        prefix[i] = gcd(prefix[i-1], nums[i]);
    }
    for (int i = n-1; i >= 1; i--) {
        suffix[i] = gcd(suffix[i+1], nums[i]);
    }

    ll ans = max(prefix[n-1], suffix[2]);
    for (int i = 1; i <= n-1; i++) {
        ans = max(ans, gcd(prefix[i], suffix[i+2]));
    }
    cout << ans;

}