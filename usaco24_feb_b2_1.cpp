#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, m; cin >> n >> m;
    string s; cin >> s;
    ll ans = 0;
    vector<ll> arr(n);
    for (ll &i : arr) {
        cin >> i;
        ans += i;
    }

    

    for (int b = 0; b < n; b++) {
        int a = (b-1+n)%n, c = (b+1)%n;

        if (s[a] != s[c] && s[c] == 'L') {
            if (s[b] == 'L') {
                int d = c;
                ll highest = arr[d];
                while (s[d] == 'L' && arr[d] < m) {
                    highest = max(highest, arr[d]);
                    d = (d+1)%n;
                }
                ans -= min(m, highest);
            }
            else {
                int d = a;
                ll highest = arr[d];
                while (s[d] == 'R' && arr[d] < m) {
                    highest = max(highest, arr[d]);
                    d = (d-1+n)%n;
                }
                ans -= min(m, highest);
            }
        }
    }

    cout << ans;
}