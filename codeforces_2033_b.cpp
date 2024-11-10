#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


void solve() {
    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (auto& v : arr) {
        for (auto& i : v) {
            cin >> i;
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int curr = 0;
        for (int k = 0; k <= i; k++) {
            curr = min(curr, arr[n-i+k-1][k]);
        }
        ans += -curr;
    }
    for (int i = 0; i < n-1; i++) {
        int curr = 0;
        for (int k = 0; k <= i; k++) {
            curr = min(curr, arr[i-k][n-k-1]);
        }
        ans += -curr;
    }

    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while(t--) solve();
}