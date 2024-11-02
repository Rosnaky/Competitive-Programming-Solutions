#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int &i : a) cin >> i;

    for (int i = 1; i < n; i++) {
        if (abs(a[i] - a[i-1]) != 5 && abs(a[i]-a[i-1]) != 7) {
            cout << "NO\n"; return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}