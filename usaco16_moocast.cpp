#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool valid(int a, int b, vector<vector<int>>& cows) {
    double x1 = cows[a][0], y1 = cows[a][1], p = cows[a][2];
    double x2 = cows[b][0], y2 = cows[b][1];

    // cout << (((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1))) << " " << p*p << "\n";

    return (((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1))) <= p*p;
}


int dfs(int node, vector<vector<int>>& cows, vector<bool>& seen) {    
    seen[node] = true;

    int ans = 0;

    for (int i = 0; i < cows.size(); i++) {
        if (!seen[i] && valid(node, i, cows)) {
            ans = max(ans, dfs(i, cows, seen)+1);
            cout << node << " " << i << " " << ans << "\n";
        }
    }

    return ans;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int n;
    cin >> n;

    vector<vector<int>> cows;

    for (int i = 0; i < n; i++) {
        int x, y, p;
        cin >> x >> y >> p;

        cows.push_back({x, y, p});
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        vector<bool> seen(n, false);
        ans = max(ans, dfs(i, cows, seen)+1);
    }

    cout << ans;
}