#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;


bool check(string &s, int i, int n) {
    if (!(i < n-3)) return 0;
    return s[i] == '1' && s[i+1] == '1' && s[i+2] == '0' && s[i+3] == '0';
}

void solve() {

    string s; cin >> s;
    int n = s.size();
    set<int> points;

    for (int i = 0; i < n-3; i++) {
        if (check(s, i, n)) points.insert(i);
    }

    int q; cin >> q;
    while (q--) {
        int i, v; cin >> i >> v;
        i--;
        s[i] = v + '0';
        int left = i;
        for (; left >= 0 && i-left < 4; left--) {
            if (points.find(left) != points.end()) break;
        }

        if (left >= 0 && i-left < 4) {
            if (!check(s, left, n)) points.erase(left); 
        }

        left = min(i, n-3);
        for (; left >= 0 && i-left < 4; left--) {
            if (check(s, left, n)) points.insert(left);
        }

        if (points.size()) {
            cout << "YES\n";
        }
        else cout << "NO\n";

    }

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}