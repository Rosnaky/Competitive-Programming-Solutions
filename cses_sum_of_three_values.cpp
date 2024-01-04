#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, x; cin >> n >> x;

    vector<pair<int, int>> nums(n);
    for (int i = 1; i <= n; i++) {
        int temp; cin >> temp;
        nums[i-1] = {temp, i};
    }

    sort(nums.begin(), nums.end());

    int i = 0;

    for (int i = 0; i < n-2; i++) {
        int target = x-nums[i].first;

        int l = i+1, r = n-1;

        while (r > l) {
            int s = nums[l].first+nums[r].first;

            if (s > target) {
                r--;
            }
            else if (s < target) {
                l++;
            }
            else {
                cout << nums[i].second << " " << nums[l].second << " " << nums[r].second;
                return 0;
            }
        }
    }
    

    cout << "IMPOSSIBLE";
}