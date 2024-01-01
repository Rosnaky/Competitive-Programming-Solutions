#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;

    vector<ll> prefix(n+1); int temp; cin >> prefix[1];
    for (int i = 2; i <= n; i++) {
        cin >> temp;
        prefix[i] = temp+prefix[i-1];
    }

    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;

        cout << prefix[r]-prefix[l] << "\n";
    }
}