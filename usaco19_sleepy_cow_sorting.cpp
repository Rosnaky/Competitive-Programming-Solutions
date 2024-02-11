#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);

    int n; cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;

    int ans = 0, prev = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i-1]) continue;
        ans += i-prev;
        prev = i;
    }

    cout << ans;
}