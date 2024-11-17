#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


void solve() {

    int k; cin >> k;
    vector<int> a(k);

    for (int & i : a) cin >> i;

    vector<int> freq(2*1e5+1);

    for (int i = 0 ; i < k; i++) freq[a[i]]++;

    for (int i = 0; i < k; i++) {
        freq[a[i]]--;
        if ((k-2)%a[i] == 0) {
            if (freq[(k-2)/a[i]] > 0) {
                cout << a[i] << " " << (k-2)/a[i] << '\n';
                break;
            }
        }
    }

}

int main() {

    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}