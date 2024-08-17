#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);

    int n; cin >> n;

    while (n--) {
        string t; cin >> t;

        if (t.size() >= 3 && t[0] == '1' && t[1] == '0' && (t[2] != '0' && (t[2] != '1' || t.size() > 3))) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }    
}