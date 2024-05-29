#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int n; cin >> n;

    vector<int> nums(n);
    for (int& i : nums) cin >> i;

    sort(nums.begin(), nums.end());

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int curr = 1, pos = i, t = 1;

        // cout << nums[i] << ": ";
        
        while (pos >= 0) {
            int j = pos-1;
            bool bad = true;
            for (; j >= 0 && nums[pos] - nums[j] <= t; j--) {
                curr++;
                bad = false;
                // cout << nums[j] << " ";
            }
            if (bad) break;
            pos = j+1;
            t++;
        }

        pos = i, t = 1;

        while (pos < n) {
            int j = pos+1;
            bool bad = true;
            for (; j < n && nums[j] - nums[pos] <= t; j++) {
                bad = false;
                curr++;   
                // cout << nums[j] << " ";
            }
            if (bad) break;
            pos = j-1;
            t++;
        }
        // cout << endl;

        ans = max(ans, curr);
    }
    cout << ans;
}


/*
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int n; cin >> n;

    vector<int> nums(n);
    for (int& i : nums) cin >> i;

    sort(nums.begin(), nums.end());

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int curr = 1, t = 1;

        while (i - t >= 0 && i + t < n && nums[i-t+1] - nums[i-t] <= t && nums[i+t] - nums[i+t-1] <= t) {
            curr+=2, t++;
        }

        ans = max(ans, curr);
    }
    cout << ans;
}
*/