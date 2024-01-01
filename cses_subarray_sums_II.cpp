#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x; cin >> n >> x;

    map<ll, int> seen;
    seen[0] = 1;
    ll ans = 0, sums = 0;

    while (n--) {
        int a; cin >> a;
        sums += a;
        if (seen.count(sums-x)) {
            ans+=seen[sums-x];
        }
        seen[sums]++;
    }

    cout << ans;
}