#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("lifeguards.in", "r", stdin); freopen("lifeguards.out", "w", stdout);

    int n; cin >> n;

    vector<pair<int, int>> times(n);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        times[i] = {a, b};
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<bool> seen(1001); int curr = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            for (int k = times[j].first; k < times[j].second; k++) {
                if (seen[k]) continue;
                curr++; seen[k] = true;
            }
        }
        ans = max(ans, curr);
        // cout << i << " " << curr << "\n";
    }

    cout << ans;
}