#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x; cin >> n >> x;

    vector<int> nums(n);

    for (int& i : nums) {
        cin >> i;
    }


    int l = 0;
    int ans = 0;
    int a = 0;
    for (int r = 0; r < n; r++) {
        ans += nums[r];
        while (ans > x) {
            ans -= nums[l];
            l++;
        }
        if (ans == x) a++;
    }

    cout << a;
}