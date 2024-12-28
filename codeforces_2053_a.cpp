#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


void solve() {
    int n; cin >> n;

    vector<int> a(n);

    for (int& i : a) cin >> i;

    for (int i = 0; i < n-1; i++) {
        for (int k = 1; k <= 2; k++) {
            int j = min(k+i, n-1);
            bool good = 1;
            for (int x = i; x <= j; x++) {
                for (int y = i; y <= j; y++) {
                    for (int z = i; z <= j; z++) {
                        if (a[x] + a[y] <= a[z]) {
                            good = 0;
                            break;
                        }
                        if (a[x] + a[z] <= a[y]) {
                            good = 0;
                            break;
                        }
                        if (a[y] + a[z] <= a[x]) {
                            good = 0;
                            break;
                        }
                    }
                }
            }

            if (good) {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}