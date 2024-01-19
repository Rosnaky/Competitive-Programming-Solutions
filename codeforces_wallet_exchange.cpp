#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void solve() {
    int a, b; cin >> a >> b;

    if ((a%2 == 1 && b%2 == 1) || (a%2 == 0 && b%2 == 0)) {
        cout << "Bob\n";
    }
    else {
        cout << "Alice\n";
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while (t--) solve();
}