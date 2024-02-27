#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <set>

using namespace std;


int pow(int a, int b) {
    int ans = 1;
    for (int i = 0; i < b; i++) {
        ans*=a;
    }
    return ans;
}

void solve() {

    int a, b, l; cin >> a >> b >> l;

    int x = 1, c = a, d = b, y = 1;
    while (c < l) {
        x++;
        c*=a;
    }
    while (d < l) {
        y++;
        d*=b;
    } 

    set<int> ans;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j<= y; j++) {
            double k = (double)l/pow(a, i)/pow(b, j);

            if (k == floor(k)) ans.insert(k);
        }
    }

    
    cout << ans.size() << "\n";
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}