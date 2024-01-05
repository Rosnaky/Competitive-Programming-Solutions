#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    map<char, int> m;
    string s; cin >> s;
    set<char> t;

    for (char i : s) {
        t.insert(i);
    }
    int ans = n, cant = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && cant<t.size()) {
            m[s[j]]++;
            if (m[s[j]] == 1) {
                cant++;
            }
            j++;
        }
        if (cant == m.size()) {
            ans = min(ans, j-i);
        }
        m[s[i]]--;
        if (m[s[i]] == 0) {
            cant--;
        }
    }
    cout << ans;
}