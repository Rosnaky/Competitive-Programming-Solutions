#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


void solve() {
    
    int n, m; cin >> n >> m;

    vector<vector<int>> nums(m, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> nums[j][i];
        }
    }

    long long ans = 0;

    for (auto&v : nums) {
        sort(v.begin(), v.end());

        long long curr = v[0];
        for (int i = 1; i < n; i++) {
            ans += (long long) v[i]*i-curr;
            curr += v[i];
        }
    }

    cout << ans << "\n";
    
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;

    while (t--) solve();
}