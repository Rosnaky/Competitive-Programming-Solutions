#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<int> nums(2*n);
    for (int& i : nums) cin >> i;

    sort(nums.begin(), nums.end());

    int ans = 1e9;
    for (int i = 0; i < 2*n; i++) {
        for (int j = 0; j < i; j++) {

            vector<int> modified;
            for (int k = 0; k < 2*n; k++) {
                if (k != i && k != j) modified.push_back(nums[k]);
            }

            int curr = 0;
            for (int k = 0; k < 2*n-2; k+=2) {
                curr += abs(modified[k]-modified[k+1]);
            }

            ans = min(ans, curr);
        }
    }

    cout << ans;
}