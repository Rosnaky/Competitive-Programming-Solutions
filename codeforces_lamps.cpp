#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp1(const pair<int, int>& x, const pair<int, int>& y) { return x.first < y.first; }
bool cmp2(const pair<int, int>& x, const pair<int, int>& y) { return x.second > y.second; }

void solve() {

    int n; cin >> n;
    vector<pair<int, int>> nums(n);
    for (auto& i : nums) {
        int a, b; cin >> a >> b;
        i = {a, b};
    }

    sort(nums.begin(), nums.end(), cmp1);
    sort(nums.begin(), nums.end(), cmp2);

    // for (auto p : nums) cout << p.first << " " << p.second << "\n";

    int ans = 0;

    vector<bool> broken(n);
    vector<bool> on(n);
    int i = 0, curr = 0;
    for (; i < n; i++) {
        auto [a, b] = nums[i];

        if (!broken[i]) {
            curr++;
            on[i] = true;
            int temp = curr;
            for (int j = 0; j < n; j++) {
                if (nums[j].first <= curr && !broken[j]) {
                    if (on[j]) temp--;
                    broken[j] = true;
                }
            }
            ans += b;
            curr = temp;
        }
    }

    cout << ans << "\n";

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;

    while (t--) solve();
}