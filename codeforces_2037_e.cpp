#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


void solve() {

    int n; cin >> n;

    string s = "";
    for (int i = 0; i < n; i++) {
        s += '0';
    }

    for (int i = 1; i < n; i++) {
        cout << "? " << i << " " << i+1 << '\n';
        int t; cin >> t;
        cout.flush();

        if (t >= 2 || t < 0) {
            cout << "! IMPOSSIBLE\n";
            cout.flush();
            return;
        }
        if (t) {
            if (!(i-1) && s[i-1] != '0') {
                cout << "! IMPOSSIBLE\n";
                cout.flush();
            } 
            s[i] = '1';
        } 

        cout << s << "\n\n";
    }

    cout << "! " << s << '\n';

}


int main() {

    // ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();

}