#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    map<ll, ll> seen;
    seen[0] = 1;

    int n; cin >> n; 
    ll ans = 0, sums = 0;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;

        sums = ((sums+a)%n+n)%n;

        if (seen.count(sums)) ans += seen[sums];

        seen[sums]++;
    }

    cout << ans;
}