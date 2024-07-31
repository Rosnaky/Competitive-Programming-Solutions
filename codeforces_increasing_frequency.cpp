#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    vector<int> dp(500001);
    int mx = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;

        if (c == k) cnt++;
        else dp[c] = max(dp[c], cnt) + 1;
        mx = max(mx, dp[c]-cnt);
    }

    cout << mx + cnt << endl;

    
}