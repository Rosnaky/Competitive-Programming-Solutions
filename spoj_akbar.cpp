#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

void solve() {
    ll n, r, m;
    cin >> n >> r >> m;

    vector<vector<ll>> graph(n+1);
    for (ll i = 0; i < r; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    
    queue<vector<ll>> stack;
    vector<bool> seen(n+1);

    for (ll i = 0; i < m; i++) {
        ll k, s;
        cin >> k >> s;
        vector<bool> processed(n+1);

        stack.push({k, s});

        while (!stack.empty()) {
            ll base = stack.front()[0], strength = stack.front()[1]; stack.pop();
            if (processed[base]) continue;
            processed[base] = true;

            if (seen[base]) {
                cout << "No\n";
                return;
            }
            seen[base] = true;

            if (strength == 0) continue;

            for (ll a : graph[base]) {
                stack.push({a, strength-1});
            }
        }
    }

    cout << "Yes\n";
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--) solve();
}