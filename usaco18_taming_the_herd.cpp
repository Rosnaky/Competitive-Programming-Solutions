#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);

    int n; cin >> n;

    vector<int> nums(n);

    for (int &i : nums) cin >> i;
    nums[0] = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] < 0) continue;

        for (int j = 1; j <= nums[i]; j++) {
            if (nums[i-j] != nums[i]-j && nums[i-j] >= 0) {
                cout << -1;
                exit(0);
            }
            nums[i-j] = nums[i]-j;
        }
    }

    int broke = 0, unknown = 0;
    for (int i = 0; i < n; i++) {
        if (!nums[i]) broke++;
        else if (nums[i] < 0) unknown++;
    }

    cout << broke << " " << broke+unknown;
}