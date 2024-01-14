#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> a(n), p(n), b(n);
    map<int, int> compress;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> p[i];
        b[i]++;
        compress[a[i]], compress[b[i]];    
    }

    int coords = 0;
    for (auto& v : compress) {
        v.second = coords++;
    }

    vector<vector<pair<int, int>>> projects(coords);

    for (int i = 0; i < n; i++) {
        projects[compress[b[i]]].emplace_back(compress[a[i]], p[i]);
    }

    vector<ll> dp(coords, 0);

    for (int i = 0; i < coords; i++) {
        if (i > 0) dp[i] = dp[i-1];
        for (auto p : projects[i]) {
            dp[i] = max(dp[i], dp[p.first]+p.second);
        }
    }
    cout << dp[coords-1];
}