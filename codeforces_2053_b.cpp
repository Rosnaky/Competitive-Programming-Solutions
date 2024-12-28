#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


void solve() {

    int n; cin >> n;
    vector<vector<int>> w(n, vector<int>(2));
    for (auto& v : w) {
        for (int &i : v) cin >> i;
    }

    // vector<int> prefix(10);
    vector<int> prefix(2*n+1);

    for (int i = 0; i < n; i++) {
        if (w[i][0] != w[i][1]) continue;
        prefix[w[i][0]]=1;
    }

    for (int i = 1; i < prefix.size(); i++) {
        prefix[i] += prefix[i-1];
        // cout << prefix[i] << '\n';
    }

    // vector<int> prefix1(10);
    vector<int> prefix1(2*n+1);

    for (int i = 0; i < n; i++) {
        if (w[i][0] != w[i][1]) continue;
        prefix1[w[i][0]]++;
    }

    for (int i = 1; i < prefix1.size(); i++) {
        prefix1[i] += prefix1[i-1];
        // cout << prefix[i] << '\n';
    }

    for (int i = 0; i < n; i++) {
        // int offset = w[i][0] == w[i][1];

        if (w[i][0] == w[i][1]) {
            if (prefix1[w[i][0]] - prefix1[w[i][1]-1] >= 2) cout << 0;
            else cout << 1;
        }
        else {

            if (prefix[w[i][1]] - prefix[w[i][0]-1] >= w[i][1]-w[i][0]+1) {
                cout << 0;
            }
            else {
                cout << 1;
            }
        }
    }

    cout << '\n';

    

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}