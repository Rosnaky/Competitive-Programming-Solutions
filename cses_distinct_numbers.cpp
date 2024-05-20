#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> nums(n);

    for (int& i : nums) cin >> i;

    sort(nums.begin(), nums.end());

    int a = 0;

    for (int i = 0; i < n; i++) {
        a++;
        int curr = nums[i];
        while (nums[i+1] == curr) i++;
    }
    cout << a;
}