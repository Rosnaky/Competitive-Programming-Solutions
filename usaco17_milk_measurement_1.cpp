#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

vector<pair<char, int>> a[107];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int day, inc; string cow;
        cin >> day >> cow >> inc;
        a[day].push_back({cow[0], inc});
    }

    int curr[3] = {7, 7, 7}, on[3] = {1, 1, 1}, ans = 0;
    for (int i = 0; i < 107; i++) {
        if (a[i].size() == 0) continue;

        for (auto p : a[i]) {
            if (p.first == 'B') curr[0] += p.second;
            else if (p.first == 'E') curr[1] += p.second;
            else if (p.first == 'M') curr[2] += p.second;
        }

        int mx = max({curr[0], curr[1], curr[2]});
        int temp[3] = {0};

        for (int j = 0; j < 3; j++) {
            if (curr[j] == mx) temp[j] = 1;
        }
        for (int j = 0; j < 3; j++) {
            if (on[j] != temp[j]) {ans++; break;}
        }
        for (int j = 0; j < 3; j++) {
            on[j] = temp[j];
        }
    }
    cout << ans;
}