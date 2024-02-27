#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        long long ans = 0;
        while (n--) {
            int a; cin >> a;
            ans += abs(a);
        }
        cout << ans << "\n";
    }
}