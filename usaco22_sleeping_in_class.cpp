#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


void solve() {

    int n; cin >> n;

    vector<int> nums(n);
    for (int& i: nums) cin >> i;

    int sum = 0;
    for (int i : nums) sum += i;

    vector<int> factors;
    for (int i = 1; i <= sqrt(sum); i++) {
        if ((double)sum/i == sum/i) {
            factors.push_back(i);
            factors.push_back(sum/i);
        }
    }

    int ans = 1e9;
    for (int f : factors) {
        int curr = 0;
        for (int i = 0; i < n; i++) {
            curr += nums[i];
            if (curr == f) { 
                curr = 0;
            }
            else if (curr > f) {
                curr = 1e9;
                break;
            }
        }
        if (curr == 1e9) continue;
        ans = min(ans, n-sum/f);
    }

    cout << (ans == 1e9 ? 0 : ans) << "\n";

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;

    while (t--) solve();
}