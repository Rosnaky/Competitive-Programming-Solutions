#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("stacking.in", "r", stdin);
    freopen("stacking.out", "w", stdout);

    int n, k; cin >> n >> k;

    vector<int> a(n+1);
    for (int i = 0; i < k; i++) {
        int l, r; cin >> l >> r;
        l--, r--;
        a[l]++, a[r+1]--;
    }

    int sol[1000000];
    int tot = 0;
    for (int i = 0; i < n; i++) {
        tot += a[i];
        sol[i] = tot;
    }

    sort(sol, sol+n);
    cout << a[n/2] << endl;
}