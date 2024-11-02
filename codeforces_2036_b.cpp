#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    // vector<int> b(k), c(k);

    vector<int> sums(k+1);
    for (int i = 0; i < k; i++) {
        int s, t; cin >> s >> t;
        sums[s] += t;
    }

    sort(sums.rbegin(), sums.rend());

    int ans = 0;
    for (int i = 0; i < min(n, k+1); i++) {
        ans += sums[i];
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}