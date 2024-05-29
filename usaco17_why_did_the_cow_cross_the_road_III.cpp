#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(const pair<int, int>& x, const pair<int, int>& y) { return x.second < y.second; }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    int n; cin >> n;

    vector<pair<int, int>> cows(n);
    for (auto &i : cows) {
        int a, b; cin >> a >> b;
        i = {b, a};
    }

    sort(cows.begin(), cows.end(), cmp);

    int ans = 0, time = 0;
    for (int i = 0; i < n; i++) {
        ans += (time < cows[i].second ? cows[i].second - time : 0) + cows[i].first;
        time = time < cows[i].second ? cows[i].second + cows[i].first : time + cows[i].first;
    }

    cout << ans;
}