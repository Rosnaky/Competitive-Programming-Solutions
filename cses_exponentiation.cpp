#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
#define mod int(1e9+7)
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    while (n--) {
        ll a, b; cin >> a >> b;

        ll ans = 1;

        while (b) {
            a %= mod;
            ans %= mod;
            if (b%2 == 1) ans = (ans*a)%mod;
            a = (a*a)%mod;
            b/=2;
        }

        cout << ans << "\n";
    }
}