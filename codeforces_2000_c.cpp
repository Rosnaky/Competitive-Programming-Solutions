#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int &i : a) cin >> i;

    

    int m; cin >> m;
    while (m--) {
        string b; cin >> b;
        if (b.size() != n) {
            cout << "No\n";
            continue;
        }

        map<int, char> umap;
        map<char, int> revumap;
        bool good = 1;
        for (int i = 0; i < b.size(); i++) {
            if (umap.count(a[i]) || revumap.count(b[i])) {
                if (umap[a[i]] != b[i] || revumap[b[i]] != a[i]) {
                    cout << "NO\n";
                    good = 0;
                    break;
                }
            }
            else {
                umap[a[i]] = b[i];
                revumap[b[i]] = a[i];
            }
        }
        if (good) cout << "YES\n";
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}