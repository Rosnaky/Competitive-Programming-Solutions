#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;


ll max_weights(int n, int m, vector<int> x, vector<int> y, vector<int> w) {
    
    vector<vector<ll>> dp(n+1, vector<ll>(n, -1));
    for (int i = 0; i < n; i++) {
        dp[n][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        if (x[i] == n-1) dp[n][y[i]] = w[i];
    }

    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            
        }
    }
    
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


}