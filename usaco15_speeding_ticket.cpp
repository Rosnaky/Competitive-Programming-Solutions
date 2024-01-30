#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int n, m; cin >> n >> m;

    vector<int> speeds;

    int curr = 0;
    for (int i = 0; i < n; i++) {
        int length, limit; cin >> length >> limit;
        for (int j = curr; j < curr+length; j++) {
            speeds.push_back(limit);
        }
        curr += length;
    }

    int ans = 0; curr = 0;
    for (int i = 0; i < m; i++) {
        int length, limit; cin >> length >> limit;
        for (int j = curr; j < curr+length; j++) {
            ans = max(ans, limit-speeds[j]);
        }
        curr += length;
    }
    cout << ans;
}