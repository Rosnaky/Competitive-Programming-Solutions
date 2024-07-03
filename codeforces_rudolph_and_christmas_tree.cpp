#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;

void solve() {

    // freopen("input.in", "r", stdin);
    double n, b, h; cin >> n >> b >> h;

    vector<int> nums(n);
    for (int &i : nums) cin >> i;

    double area = b*h/2.0;
    double ans = area*n;

    for (int i = 0; i < n-1; i++) {
        int overlap = nums[i] + h - nums[i+1];
        if (overlap > 0) {
            double ratio = (double) overlap / h;
            ans -= area * ratio * ratio;
        }
    }

    cout << ans << endl;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(numeric_limits<double>::max_digits10);

    int t; cin >> t;
    while (t--) solve();
}