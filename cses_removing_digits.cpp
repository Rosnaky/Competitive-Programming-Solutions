#include <vector>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> dp(n+1, 1e9);
    dp[n] = 0;
    
    for (int i = n; i >= 0; i--) {
        string temp = to_string(i);
        for (char c : temp) {
            dp[i-c+'0'] = min(dp[i-c+'0'], dp[i]+1);
        }
    }
    cout << dp[0];
}