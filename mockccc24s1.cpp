#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int ans = 1e9;

void join(vector<bool>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        if (!nums[i]) continue;

        while (i < nums.size() && nums[i]) {
            nums[i] = 0;
            i++;
        }
        nums[i-1] = 1;
    }

    for (bool a : nums) cout << a;
    cout << "\n";

    int curr = 0;
    for (bool i : nums) curr+=i;
    ans = min(ans, curr);
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    vector<bool> nums(n);
    string s; cin >> s;

    for (int i = 0; i < n; i++) {
        nums[i] = s[i]-'0';
    }

    join(nums);

    while (k--) {
        int i = 0;
        int left = -1;
        int minD = 1e9, index = -1;
        for (; i < n; i++) {
            if (nums[i] && left!=-1) {
                if ((i-left)%2 == 0 && (i-left) < minD) {
                    minD = i-left;
                    index = (i+left)/2;
                }
            }
            if (nums[i]) left=i;
        }

        if (index != -1) {
            nums[index] = true;
            join(nums);
        }
        else {
            k = 0;
        }
    }

    cout << ans;
}