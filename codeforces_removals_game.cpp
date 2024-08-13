#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);

    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    bool good = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            good = 0;
            break;
        }
    }

    if (!good) {
        good = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[n-i-1]) {
                good = 0;
                break;
            }
        }
    }

    if (good) {
        cout << "Bob\n";
        return;
    }

    cout << "Alice\n";
    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}