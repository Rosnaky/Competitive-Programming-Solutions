#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int n; cin >> n;
    string a, b; cin >> a >> b;

    int ans = 0;

    bool on = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            ans += on;
            on = 0;
        }
        else on = 1;
    }

    ans += on;

    cout << ans;
}