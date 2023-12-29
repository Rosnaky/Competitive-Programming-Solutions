#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        int temp = nums[i];
        for (int j = 0; j < i; j++) {
            if (temp >= nums[j]) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}