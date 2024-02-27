#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


void solve() {

    int n; cin >> n;
    vector<int> arr(n);
    
    for (int& i : arr) cin >> i;

    vector<bool> seen(n);
    seen[0] = 1;

    for (int i = 0; i < n; i++) {
        if (!seen[i]) continue;

        for (int j = i+1; j < n; j++) {
            if (arr[j]%arr[i] == 0) seen[j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}