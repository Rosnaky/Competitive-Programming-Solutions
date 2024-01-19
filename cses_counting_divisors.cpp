#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    while (n--) {
        int x; cin >> x;
        int ans = 0;
        for (int i = 1; i <= sqrt(x); i++) {
            if (x%i == 0) ans+=1 + (i != sqrt(x));
        }
        cout << ans << "\n";
    }
}
