#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("shell.in", "r", stdin); freopen("shell.out", "w", stdout);

    int n; cin >> n;

    int ans = 0;

    vector<vector<int>> queries(n, vector<int>(3));
    for (vector<int>& q : queries) cin >> q[0] >> q[1] >> q[2];

    for (int cup = 1; cup <= 3; cup++) {
        int p = cup;
        int curr = 0;
        for (vector<int>& q : queries) {
            if (p == q[0]) p = q[1];
            else if (p == q[1]) p = q[0];

            if (p == q[2]) curr++; 
        }
        ans = max(ans, curr);
    }

    cout << ans;
}