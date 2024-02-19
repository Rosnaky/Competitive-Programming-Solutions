#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


void solve() {
    int n; cin >> n;
    vector<bool> dp(n+1);

    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] == 0) {
                string a = to_string(i-j);
                string b = a;
                reverse(b.begin(), b.end());
                if (a == b) {
                    dp[i] = 1;
                    break;
                }
            }
        }
    }

    cout << (dp[n] ? 'B' : 'E') << "\n";
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}