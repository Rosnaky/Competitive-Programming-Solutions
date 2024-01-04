#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("pairup.in" ,"r", stdin); freopen("pairup.out", "w", stdout);


    int n; cin >> n;

    vector<pair<int, int>> cows(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        cows[i] = {y, x};
    }
    sort(cows.begin(), cows.end());

    int l = 0, r = n-1;
    int ans = 0;

    while (r > l) {
        if (cows[l].second == 0) {
            l++;
            continue;
        }        
        if (cows[r].second == 0) {
            r--;
            continue;
        }
        cows[l].second--;
        cows[r].second--;
        ans = max(ans, cows[l].first+cows[r].first);
    }
    while (cows[l].second > 0) {
        cows[l].second--;
        ans = max(ans, cows[l].first);
    }

    cout << ans;
}