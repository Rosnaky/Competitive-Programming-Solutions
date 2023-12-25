#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int& i : nums) {
        cin >> i;
    }

    int ans = 1e9;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) solve();
}