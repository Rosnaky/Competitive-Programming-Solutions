#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);

    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    string ans;

    for (int i = 0; i < n; i++) {
        ans += s[i];
        if (ans.size() > m && ans.substr(ans.size()-m) == t) {
            ans.resize(ans.size()-m);
        }
    }

    cout << ans;
}