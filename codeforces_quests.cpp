#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

void solve() {

    int n, k; cin >> n >> k;

    
    vector<int> a(n), b(n);

    cin >> a[0];
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    cin >> b[0];
    for (int i = 1; i < n; i++) {
        cin >> b[i];
        b[i] = max(b[i], b[i-1]);
    }
    
    int ans = 0;
    for (int i = 0; i < min(k, n); i++) {
        ans = max(ans, a[i] + b[i]*(k-i-1));
    }    

    cout << ans << endl;


}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}