#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {

    int n, m; cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));

    for (vector<int>& v : a) {
        string s; cin >> s;
        for (int i = 0; i < n; i++) {
            v[i] = s[i];
        }
    }
    for (vector<int>& v : b) {
        string s; cin >> s;
        for (int i = 0; i < n; i++) {


            v[i] = s[i];
        }
    }




}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();

    int t; cin >> t;

    while (t--) solve();

}