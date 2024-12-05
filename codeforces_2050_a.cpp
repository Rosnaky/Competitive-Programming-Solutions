#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    int ans = 0;

    int curr = 0;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        curr += s.size();
        if (curr <= m) ans++;
    }

    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}