#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {

    int n; cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    vector<bool> seats(n+1);
    seats[a[0]] = 1;

    for (int i = 1; i < n; i++) {
        bool valid = 0;
        if (a[i]-1 > 0) valid |= seats[a[i]-1];
        if (a[i]+1 <= n) valid |= seats[a[i]+1];

        if (!valid) {
            cout << "NO\n";
            return;
        }

        seats[a[i]] = 1;
    }

    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}