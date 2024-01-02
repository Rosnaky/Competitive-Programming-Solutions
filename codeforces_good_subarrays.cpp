#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;

    string temp; cin >> temp;

    ll ans = 0, sum = 0;
    map<int, int> seen;
    seen[0] = 1;

    for (int i = 0; i < n; i++) {
        sum += temp[i]-'0';
        ans += seen[sum-i-1];
        seen[sum-i-1]++;
    }
    cout << ans << "\n";
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}