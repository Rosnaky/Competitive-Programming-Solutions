#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> dp(5005);

    dp[0] = 1;
    
    while (n > 0) {
        n--;
        string s;
        int x;

        cin >> s >> x;

        if (s == "+") {
            for(int i = k; i >= x; i--) {
                dp[i] += dp[i-x];
                dp[i] %= 998244353;
            }
        }
        else {
            for (int i=x; i <= k; i++) {
                dp[i] += (998244353-dp[i-x]);
                dp[i] %= 998244353;
            }
        }
        cout << dp[k] << "\n";
    }
}