#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int count = 0;
    for (char c : s) count += c == 'U';

    if (count%2) cout << "yes\n";
    else cout << "no\n";

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    while (n--) solve();
}