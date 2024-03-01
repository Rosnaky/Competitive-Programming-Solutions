#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<int> nums(n);
    for (int &i : nums) cin >> i;


    sort(nums.rbegin(), nums.rend());

    int a = 3;

    for (int i = 0; i < n; i++) {
        a--;
        int j = i, count = 0;
        while (j < n && nums[j] == nums[i]) j++, count++;
        if (!a) {
            cout << nums[i] << " " << count; return 0;
        }
        i = j-1;
    }
}