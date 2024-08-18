#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


void solve() {

    int n; cin >> n;

    vector<int> ans(n+1, 1);

    for (int k = 1; k <= n; k++) {
        for (int i = k; i <= n; i+=k) {
            if (ans[i]%k) ans[i] *= k;
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << '\n';

}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}