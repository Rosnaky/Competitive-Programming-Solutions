#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("diamond.in", "r", stdin); freopen("diamond.out", "w", stdout);

    int n, k; cin >> n >> k;

    vector<int> nums(n);

    for (int& i : nums) cin >> i;
    sort(nums.begin(), nums.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (nums[j]-nums[i] > k) break;
            ans = max(ans, j-i+1);
        }
    }
    cout << ans;
}