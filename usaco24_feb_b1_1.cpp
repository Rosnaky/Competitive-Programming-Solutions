#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void solve() {
    string n; cin >> n;
    
    if (n[n.size()-1] == '0') cout << "E\n";
    else cout << "B\n";
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}