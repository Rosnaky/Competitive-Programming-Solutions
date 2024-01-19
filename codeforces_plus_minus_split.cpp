#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += s[i] == '+' ? 1 : -1;
    }
    cout << abs(ans) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while(t--) solve();
}