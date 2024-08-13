#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool valid(vector<int>& p, vector<int>& a) {
    
    int n = p.size();

    vector<vector<int>> adj(66000);
    for (int i = 1; i < n; i++) {
        adj[a[i]].push_back(p[i]);
    }

}

void solve() {

    int n, q; cin >> n >> q;

    vector<int> a(n);
    a[0] = 1;

    for (int i = 1; i < n; i++) cin >> a[i];

    vector<int> p(n);
    for (int &i : p) cin >> i;

    while (q--) {

        int x, y; cin >> x >> y;

        int temp = p[x];
        p[x] = p[y];
        p[y] = temp;

        

        if (valid(p, a)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }

    }

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;

    while (t--) solve();
}