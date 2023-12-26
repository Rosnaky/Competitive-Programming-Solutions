#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);


    ll n, xl, yl, xb, yb;
    cin >> n >> xl >> yl >> xb >> yb;

    if (xl == xb && yl == yb) {cout << 0; return 0;}

    vector<vector<ll>> lasers(n);

    for (vector<ll>& l : lasers) {
        ll a, b;
        cin >> a >> b;
        l = {a, b};
    }
    lasers.push_back({xb, yb});
    lasers.push_back({xl, yl});

    vector<vector<ll>> vertical(n+2);
    vector<vector<ll>> horizontal(n+2);
    
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (i == j) continue;
            if (lasers[i][0] == lasers[j][0]) vertical[i].push_back(j), vertical[j].push_back(i);
            if (lasers[i][1] == lasers[j][1]) horizontal[i].push_back(j), horizontal[j].push_back(i);
        }
        if (lasers[i][0] == xb) vertical[i].push_back(n), vertical[n].push_back(i);
        if (lasers[i][1] == yb) horizontal[i].push_back(n), horizontal[n].push_back(i);
        if (lasers[i][0] == xl) vertical[i].push_back(n+1), vertical[n+1].push_back(i);
        if (lasers[i][1] == yl) horizontal[i].push_back(n+1), horizontal[n+1].push_back(i);;
    }

    // for (int i = 0; i < n; i++) {
    //     int a, b;
    //     cin >> a >> b;
    //     vertical[a].push_back(b);
    //     horizontal[b].push_back(a);
    // }
    // vertical[xb].push_back(yb);
    // horizontal[yb].push_back(xb);

    int ans = 1e9;

    std::queue<vector<ll>> q;

    q.push({n+1, 0, 0}); // x y dir mirrors  // dir - 0:N 1:E 2:S 3:W
    q.push({n+1, 1, 0});

    vector<ll> seen(n+2, 1e9);
    

    while (!q.empty()) {
        vector<ll> curr = q.front();
        q.pop();
        ll node = curr[0], dir = curr[1], mirrors = curr[2];

        if (seen[node] < mirrors) continue;

        seen[node] = mirrors;

        // cout << node << " " << dir << " "<< mirrors << "\n";

        if (node == n) {
            // cout << x << " " << y << " " << dir << " "<< mirrors << "\n";
            cout << mirrors-1;
            return 0;
        }

        if (dir == 0) {
            for (int j : vertical[node]) {
                q.push({j, 1, mirrors+1});
            }
        }
        else if (dir == 1) {
            for (int j : horizontal[node]) {
                q.push({j, 0, mirrors+1});
            }
        }
    }

    cout << -1;
}