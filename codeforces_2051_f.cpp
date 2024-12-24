#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

void solve() {

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(q);
    for (int &i : a) cin >> i;

    unordered_map<int, bool> seen;
    seen[m] = 1;

    for (int i = 0; i < q; i++) {
        unordered_map<int, bool> curr;

        for (auto &p : seen) {
            int j = p.first;
            if (a[i] < j) {
                curr[j] = 1;
                curr[j-1] = 1;
            }
            else if (a[i] > j) {
                curr[j+1] = 1;
                curr[j] = 1;
            }
            else {
                curr[1] = 1;
                curr[n] = 1;
            }
        }

        int count = 0;
        for (auto &p : curr) count+=p.second;
        cout << count << " ";
        seen = curr;
    }

    cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}