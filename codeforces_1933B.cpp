#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


void solve() {

    int n; cin >> n;
    int sum = 0;
    bool good = false, good1 = false;
    while (n--) {
        int a; cin >> a;
        sum += a;
        if (a%2 == 1 && a%3 == 0) good = true;
        if (a%2 == 0) good1 = true;
    }

    if (sum%3 != 1) {cout << sum%3 << "\n"; return;}
    if (good && (sum-1)%3 == 0) cout << "1\n";
    else if (good1 && (sum-2)%3 == 0) cout << "1\n";
    else cout << "2\n";
}

int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}