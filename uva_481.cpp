#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    freopen("goesup.in", "r", stdin);

    vector<int> nums;

    int n;
    while (cin >> n) {
        nums.push_back(n);
    }

    n = nums.size();

    vector<int> child(n);
    for (int i = 0; i < n; i++) child[i] = i;

    vector<int> dp(n, 1);
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i-1; j >= 0; j--) {
            if (nums[j] < nums[i] && dp[j]+1 >= dp[ans]) {
                child[i] = j;
                ans = i;
                dp[i] = dp[j]+1;
            }
        }
    }

    cout << dp[ans] << "\n-\n";
    vector<int> res;
    while (child[ans] != ans) {
        res.push_back(nums[ans]);
        ans = child[ans];
    }
    res.push_back(nums[ans]);
    
    for (int i = res.size()-1; i >= 0; i--) {
        cout << res[i] << "\n";
    }

    // cout << ans << endl;
    // for (int c : child) cout << c << " ";
}