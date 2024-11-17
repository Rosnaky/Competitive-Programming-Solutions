#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


void solve() {

    int n, m, L; cin >> n >> m >> L;
    vector<vector<int>> hurdles(n, vector<int>(2));
    // sort(hurdles.begin(), hurdles.end());

    for (auto& v : hurdles) {
        for (auto& i : v) cin >> i;
    }

    vector<vector<int>> powerups(m, vector<int>(2));
    for (auto& v : powerups) {
        for (auto& i : v) cin >> i;
    }
    // sort(powerups.begin(), powerups.end());

    vector<int> sizes(n);
    for (int i = 0; i < n; i++) {
        sizes[i] = hurdles[i][1] - hurdles[i][0];
    }

    
    int index = 0, jump = 1, ans = 0;
    for (int i = 0; i < n; i++) {

        while (index < m && jump < sizes[i]+2 && powerups[index][0] < hurdles[i][0]) {
            jump += powerups[index][1];
            index++;
            ans++;
        }

        if (jump < sizes[i]+2) {
            cout << -1 << '\n';
            return;
        }

    }
    cout << ans << '\n';



}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}