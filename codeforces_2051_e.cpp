#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

void solve() {

    int n, k; cin >> n >> k;

    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i].second;
    }

    sort(p.begin(), p.end());

    vector<int> valid(n);
    valid[0] = n;
    int prev = 0;
    for (int i = 1; i < n; i++) {
        int curr = valid[i-1];
        while (p[prev].second < p[i].first) {
            curr--;
            prev++;
        }
        valid[i] = curr;
    }

    int ans = 0;
    int curr = 0;
    int rev = 0;

    for (int i = 0; i < n && rev <= k; i++) {
        curr = p[i].first;
        ans = max(ans, curr*valid[i]);
        if (!i || p[i].first != p[i-1].first) rev++;
    }

    cout << ans << '\n';

}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}