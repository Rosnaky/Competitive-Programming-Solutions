#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("cownomics.in", "r", stdin); freopen("cownomics.out", "w", stdout);


    int n, m; cin >> n >> m;

    vector<string> spot(n), plain(n);
    for (int i = 0; i < n; i++) {
        cin >> spot[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> plain[i];
    }

    int ans = 0;

    for (int i = 0; i < m; i++) {
        map<char, bool> seen;
        for (int j = 0; j < n; j++) {
            seen[spot[j][i]] = true;
        }
        bool valid = true;
        for (int j = 0; j < n; j++) {
            if (seen[plain[j][i]]) {
                valid = false;
                break;
            }
        }
        if (valid) ans++;
    }
    cout << ans;
    
}