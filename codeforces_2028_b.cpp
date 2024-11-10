#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

void solve() {

    ll n, b, c; cin >> n >> b >> c;
    
    
    if (b == 0 && n-c > 2) {
        // cout << (n-1)*b+c << "  " << n-1 << endl;
        cout << -1 << '\n';
        return;
    }
    ll inArr = b == 0 ? n*(c < n) : max((ll)0, (n)/b - c/b);
    ll lower = min(c, n);
    ll higher = n-inArr;
    // cout << inArr << " " << lower << " " << higher << endl; 

    // if (lower > higher) {
    //     cout << -1 << '\n';
    //     return;
    // }
    ll ans = higher;
    if (ans == 0 && b == 0) {
        ans = n-1;
    }
    

    cout << ans << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}