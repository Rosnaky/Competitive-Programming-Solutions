#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {

    int n; cin >> n;

    vector<int> arr(n);
    for (int &i : arr) {
        cin >> i;
    }
    // sort(arr.rbegin(), arr.rend());
    vector<bool> seen(n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (seen[i]) continue;
        seen[i] = 1;
        for (int j = i + 1 ; j < n; j++) {
            if (arr[i] == arr[j]) {
                seen[j] = 1;
                ans++;
                break;
            }
        }
    }

    cout << ans << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}