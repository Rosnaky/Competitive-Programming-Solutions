#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);


    int n; cin >> n;
    vector<pair<int, int>> nums(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;

        nums[i] = {x, y};
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (nums[i].first == nums[j].first) {
                for (int k = 0; k < n; k++) {
                    if (i == k || j == k) continue;
                    if (nums[i].second == nums[k].second) {
                        ans = max(ans, abs(nums[i].second-nums[j].second)*abs(nums[i].first-nums[k].first));
                    }
                    else if (nums[j].second == nums[k].second) {
                        ans = max(ans, abs(nums[i].second-nums[j].second)*abs(nums[j].first-nums[k].first));
                    }
                }
            }
        }
    }
    cout << ans;
}