#include <vector>
#include <iostream>
#include <algorithm>

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
    int l = 0, r = n-1;
    while (r > l) {
        int s = nums[l].first+nums[r].first;

        if (s > x) {
            r--;
        }
        else if (s < x) {
            l++;
        }
        else {
            cout << nums[l].second << " " << nums[r].second;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
}