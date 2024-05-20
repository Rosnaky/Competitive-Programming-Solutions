#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int n, m; cin >> n >> m;


    vector<string> spotty(n), plain(n);
    for (string&i : spotty) cin >> i;
    for (string&i : plain) cin >> i;


    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i+1; j < m; j++) {
            for (int k = j+1; k < m; k++) {

                set<vector<char>> seen;
                for (int l = 0; l < n; l++) {
                    seen.insert({spotty[l][i], spotty[l][j], spotty[l][k]});
                }

                bool good = true;
                for (int l = 0; l < n; l++) {
                    if (seen.find({plain[l][i], plain[l][j], plain[l][k]}) != seen.end()) {
                        good = false;
                        break;
                    }
                }

                ans += good;
                

            }
        }
    }

    cout << ans;
}