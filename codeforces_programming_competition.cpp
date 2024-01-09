#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> graph;
int n;

bool superior(int node, int target, vector<bool> seen) {
    if (node == target) return true;
    if (seen[node]) return false;
    seen[node] = true;
    return superior(graph[node], target, seen);
}

int maximumPairs(vector<vector<int>>& possible, vector<bool> seen) {
    int ans = 0;

    for (int i = 2; i <= n; i++) {
        if (seen[i]) continue;
        for (int a : possible[i]) {
            if (seen[a]) continue;
            vector<bool> temp = seen;
            temp[i] = true, temp[a] = true;
            ans = max(ans, maximumPairs(possible, temp)+1);
        }
    }
    return ans;
}


void solve() {
    cin >> n;

    graph = vector<int>(n+1);

    

    for (int i = 2; i <= n; i++) {
        cin >> graph[i];
    }

    vector<vector<int>> possible(n+1);

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            if (i == j) continue;
            vector<bool> temp(n+1);
            if (!superior(i, j, temp) && !superior(j, i, temp)) {
                possible[i].push_back(j);
            }
        }
    }

    // for (int i = 2; i <= n; i++) {
    //     cout << i << ": ";
    //     for (int a : possible[i]) {
    //         cout << a << " ";
    //     }
    //     cout << endl;
    // }
    vector<bool> seen(n+1);
    cout << maximumPairs(possible, seen) << "\n";

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}