#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {

    int a, b; cin >> a >> b;
    int m = min(a, b);

    while (m%a != m%b) m++;

    cout << m << '\n';

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}