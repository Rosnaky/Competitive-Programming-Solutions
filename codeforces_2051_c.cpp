#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void solve() {

    int n, m, k; cin >> n >> m >> k;
    vector<int> a(m), q(k);

    for (int &i : a) cin >> i;
    for (int &i : q) cin >> i;

    unordered_map<int, bool> umap;

    for (int i : q) umap[i] = 1;

    int knows = 0;
    for (int i : q) knows++;

    for (int i : a) {
        knows -= umap[i];
        if (knows == n-1) {
            cout << 1;
        }
        else cout << 0;
        knows += umap[i];
    }

    cout << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}