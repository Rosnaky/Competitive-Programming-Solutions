#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    vector<int> a(n), b(n);
    
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;

    vector<pair<ll, int>> ans(m);
    for (int i = 0; i < m; i++) {
        ans[i] = {0, i};
    }

    for (int i = 0; i < n; i++) {
        sort(ans.begin(), ans.end());

    }

    vector<ll> final(m);
    for (int i = 0; i < m; i++) {
        final[ans[i].second] = ans[i].first;
    }

    for (ll &i : final) cout << i << " ";
}