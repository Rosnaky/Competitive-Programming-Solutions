#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;



void solve() {

    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n;i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    map<int, int> topics;

    int l = 0, r = -1, ans = 1e9;

    while(++r<n) {
        for (int i = m/2; i <= m; i++) {
            if (a[r]%i==0) topics[i]++;
        }
        while (topics.size() == m-(m/2)) {
            ans = min(ans, a[r]-a[l]);
            for (int i = m/2+1; i<=m; i++) {
                if (a[l]%i == 0) {
                    if (!--topics[i]) {
                        topics.erase(i);
                    }
                }
            }
            l++;
        }
    }
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}