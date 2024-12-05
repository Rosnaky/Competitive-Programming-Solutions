#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {

    int n; cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    
    long long sum = 0;
    for (int i : a) sum += (long long)i;
    if ((sum%n) ) {
        cout << "NO\n";
        return;
    }
    int target = sum/n;
    // a[2] -= target-a[0];
    // a[n-3] -= target-a[n-1];
    
    vector<int> cp = a;
    bool good = 1;
    for (int i = n-1; i > 1; i--) {
        cp[i-2] -= target-cp[i];
        cp[i] = target;
        if (cp[i-2] < 0) {
            good = 0;
            break;
        }
    }
    if (good) {
        for (int i = 0; i < n; i++) {     

            if (cp[i] != target) {
                good = 0;
            }
        }
        if (good) {
            cout << "YES\n";
            return;
        }
    }

    for (int i = 0; i < n-2; i++) {
        a[i+2] -= target-a[i];
        a[i] = target;
        if (a[i+2] < 0) {
            cout << "NO\n"; return;
        }
    }

    // for (int i : a)
    // cout << a[i] << " ";
    // cout << endl;

    for (int i = 0; i < n; i++) {     

        if (a[i] != target) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}