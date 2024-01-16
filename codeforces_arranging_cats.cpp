#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void solve() {

    int n; cin >> n;
    
    vector<bool> s(n), f(n);
    string temp; cin >> temp;
    for (int i = 0; i < n; i++) {
        s[i] = temp[i]-'0';
    }
    cin >> temp;
    for (int i = 0; i < n; i++) {
        f[i] = temp[i]-'0';
    }

    int days = 0;
    for (int i = 0; i < n; i++) {
        if (!s[i] && f[i]) days++;
    }

    int curr = days;
    for (int i = 0; i < n; i++) {
        if (s[i] && !f[i]) {
            if (days) days--;
            else curr++;
        }
    }

    cout << curr << "\n";
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}