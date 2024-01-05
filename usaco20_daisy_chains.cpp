#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);


    int n; cin >> n;

    vector<int> nums(n);
    for (int& i : nums) cin >> i;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        map<double, bool> count;
        double curr = 0;
        for (int j = i; j < n; j++) {
            count[nums[j]] = true;
            curr += nums[j];
            if (count[curr/(j-i+1)]) {ans++;}
        }
    }
    cout << ans;

}