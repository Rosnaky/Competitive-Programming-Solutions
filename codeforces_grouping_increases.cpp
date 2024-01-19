#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


void solve() {
    int n; cin >> n;


    int aprev = 1e9, bprev = 1e9, ans = 0;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;

        if (num <= min(aprev, bprev)) {
            if (aprev < bprev) aprev = num;
            else bprev = num;
            continue;
        }
        else if (num <= max(aprev, bprev)) {
            if (aprev > bprev) aprev = num;
            else bprev = num;
            continue;
        }
        else {
            ans++;
            if (aprev < bprev) aprev = num;
            else bprev = num;
        }
    }
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}