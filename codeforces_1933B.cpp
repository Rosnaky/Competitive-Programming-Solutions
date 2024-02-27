#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


void solve() {

    int n; cin >> n;
    int sum = 0;
    vector<int> arr(n);
    while (n--) {
        cin >> arr[n];
        sum += arr[n];
    }

    if (sum%3 != 1) {cout << sum%3 << "\n"; return;}

    bool good = false;
    for (int i = 0; i < arr.size(); i++) {
        if ((sum-arr[i])%3 == 0) {
            good = true;
            break;
        }
    }

    if (good) cout << "1\n";
    else cout << "2\n";


}

int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}