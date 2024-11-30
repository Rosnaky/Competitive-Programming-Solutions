#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


void solve() {

    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        // cout << i << '\n';
        int curr = 0;
        int trigger = 0;
        while (i < n && s[i] == '0') {
            curr++;
            i++;
            trigger=1;

            if (curr == m) {
                ans++;
                i += k-1;
                curr = 0;
                // trigger++;
            }
        }
        // cout << i << "\n\n";
        i -= trigger;

        // cout << i << "\n\n";

    }

    cout << ans << '\n';
    

}

/*
6
5 1 1
10101
5 2 1
10101
6 3 2
000000
8 5 2
00000000
4 2 2
0000
5 2 2
00000
*/


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);


    int t; cin >> t;
    while (t--) solve();
}