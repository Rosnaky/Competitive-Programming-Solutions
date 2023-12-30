#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<pair<int, int>> objects;
vector<vector<int>> memo;
int n;
int g;

int dp(int i, int val, int weight) {
    if (i == n) return val;
    if (memo[i][val] != -1) return memo[i][val];
    int ans = 0;
    if (weight-objects[i].second >= 0) {
        ans = dp(i+1, val+objects[i].first, weight-objects[i].second);
    }
    
    ans = max(ans, dp(i+1, val, weight));

    return memo[i][val] = ans;
    
}


void solve() {
    cin >> n;


    objects = vector<pair<int, int>>(n);
    int total = 0;
    for (int i = 0; i < n; i++) {
        int p, w;
        cin >> p >> w;
        objects[i] = {p, w};
        total += p;
    }

    
    cin >> g;

    int ans = 0;
    for (int i = 0; i < g; i++) {
        int w; cin >> w;
        memo = vector<vector<int>>(n, vector<int>(100050, -1));
        ans += dp(0, 0, w);
    }

    cout << ans << "\n";
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}