#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {

    int n; cin >> n;

    string s; cin >> s;
    string r; cin >> r;

    for (int i = 0; i < n-1; i++) {

        for (int k = 0; k < s.size()-1; k++) {
            // cout << s << " " << r <<  "\n";
            if (s[k] != s[k+1] && (k == 0 || (s[k-1] != s[k] || s[k] != r[i]))) {
                s = s.substr(0, k) + r[i] + s.substr(k+2, s.size()-k-2);
                break;
            }
            if (k == s.size() - 2) {
                cout << "no\n";
                return;
            }
        }
    }

    cout << "yes\n";


}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}