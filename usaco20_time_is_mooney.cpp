#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>

using namespace std;

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);

    int n, m, c;
    cin >> n >> m >> c;
    vector<ll> money(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> money[i];
    }

    unordered_map<ll, vector<ll>> roads;
    for (int i = 0; i < m; i++) {
        ll fr, to;
        cin >> fr >> to;

        roads[fr].push_back(to);
    }

    vector<vector<ll>> dp(1005, vector<ll>(1005, -1));

    dp[0][1] = 0;
    ll ans = 0;

    for (int dist = 0; dist <= 1000; dist++) {
        for (int i = 1; i <= n; i++) {
            if (dp[dist][i] != -1) {
                if (i == 1) ans = max(ans, dp[dist][i] - dist*dist*c);

                for (int v : roads[i]) dp[dist+1][v] = max(dp[dist+1][v], dp[dist][i]+money[v]);
            }
        }
    }

    cout << ans;
}