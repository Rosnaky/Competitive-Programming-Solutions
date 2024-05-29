#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<ll> nums(n);
    
    for (ll &i: nums) {
        cin >> i;
    }

    sort(nums.begin(), nums.end());

    ll ans = 0, price = 0;
    for (int i = 0; i < n; i++) {
        if ((ll)nums[i] * (n-i) > ans) {
            ans = nums[i]*(n-i);
            price = nums[i];
        }
    }

    cout << ans << " " << price;
}