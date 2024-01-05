#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<pair<int, char>> nums(n);

    for (int i = 0; i < n; i++) {
        char c; int x;
        cin >> c >> x;
        nums[i] = {x, c};   
    }

    int ans = 1e9;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        int curr = 0;

        for (int j = i+1; j < n; j++) {
            if (nums[j].second == 'G') {
                curr += 1;
            }
        }
    
        for (int j = i-1; j >= 0; j--) {
            if (nums[j].second == 'L') {
                curr += 1;
            }
        }
        
        ans = min(curr, ans);
    }

    std::cout << ans;
}