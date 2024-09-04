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

    vector<ll> ans(m);
    vector<int> remaining = b;

    for (int i = 0; i < m; i++) {

        ll curr = m+i-1;
        for (int j = 0; j < n; j++) {
            curr += remaining[j];
            if (remaining[j] && curr >= m) {
                curr -= m;
                ans[i] += a[j];
                remaining[j]--;
            }
        }

    }

    for (ll &i : ans) cout << i << ' ';
}