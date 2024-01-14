#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    ll sum = 0;
    vector<int> nums(n);
    for (int& i : nums) {cin >> i; sum += i;}

    vector<vector<ll>> dp(n, vector<ll>(n));
    for (int l = n-1; l >= 0; l--) {
        for (int r = l; r < n; r++) {
            if (l == r) dp[l][r] = nums[l];
            else {
                dp[l][r] = max(nums[l]-dp[l+1][r], nums[r]-dp[l][r-1]);
            }
        }
    }

    cout << (sum+dp[0][n-1])/2;
}