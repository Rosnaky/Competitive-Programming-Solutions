#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n, x;
    cin >> n >> x;

    vector<int> prices(n);

    for (int& p : prices) {
        cin >> p;
    }

    vector<int> pages(n);

    for (int& p : pages) {
        cin >> p;
    }


    vector<int> dp(x+1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = x; j >= prices[i]; j--) {
            dp[j] = max(dp[j], dp[j-prices[i]] + pages[i]);
        }
    }

    int ans = 0;
    for (int i = 0; i <= x; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;
}