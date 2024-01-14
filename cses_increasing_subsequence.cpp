#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> dp;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) dp.push_back(x);
        else {
            *it = x;
        }
    }

    cout << dp.size();
}