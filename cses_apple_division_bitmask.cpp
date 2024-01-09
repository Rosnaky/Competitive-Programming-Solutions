#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> nums(n);
    for (int& i : nums) cin >> i;

    ll ans = 1e15;

    for (ll mask = 0; mask < (1<<n); mask++) {
        ll left = 0, right = 0;

        for (int i = 0; i < n; i++) {
            if ((1<<i) & mask) {
                left+=nums[i];
            }
            else {
                right+=nums[i];
            }
        }
        ans = min(ans, abs(right-left));
    }
    cout << ans;
}