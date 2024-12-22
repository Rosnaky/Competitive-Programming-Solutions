#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {

    int n, a, b, c; cin >> n >> a >> b >> c;

    int ans = (n/(a+b+c))*3;
    n %= a+b+c;

    while (n > 0) {
        if (ans%3 == 0) {
            n-=a;
        }
        else if (ans%3 == 1) {
            n-=b;
        }
        else {
            n-=c;
        }
        ans++;
    } 

    cout << ans << '\n';

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}