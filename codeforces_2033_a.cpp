#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


void solve() {
    int n; cin >> n;
    int x = 0;

    for (int i = 0; -n <= x && x <= n; i++) {
        if (x >= 0) {
            x -= 2*i+1;
        }
        else x += 2*i+1;
    }
    if (x > 0) cout << "Kosuke\n";
    else cout << "Sakurako\n";
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}