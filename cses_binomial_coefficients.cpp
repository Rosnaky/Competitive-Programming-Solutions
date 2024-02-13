#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define mod int(1e9+7)
typedef long long ll;
ll f[int(1e6)+5];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    
    f[0] = 1;
    for (int i = 1; i < 1e6+5; i++) {
        f[i] = (f[i-1]*i)%mod;
    }

    int n; cin >> n;

    while (n--) {
        int b, a; cin >> b >> a;

        cout << f[b]/f[a]/f[b-a] << "\n";
    }
}