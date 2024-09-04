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

    priority_queue<pair<ll, int>> queue;
    for (int i = 0; i < m; i++) {
        queue.push({0, -i});
    }

    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j < b[i]; j++) {
            ll next = queue.top().first - a[i];
            int id = queue.top().second;
            queue.pop();
            queue.push({next, id});
        }
    }

    vector<ll> ans(m);
    while (!queue.empty()) {
        ans[-queue.top().second] = -queue.top().first;
        queue.pop();
    }

    for (ll& i : ans) cout << i << " ";
}