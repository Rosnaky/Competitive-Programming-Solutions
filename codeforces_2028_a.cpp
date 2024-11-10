#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;


void solve() {

    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;

    queue<pair<int, int>> queue;
    queue.push({0, 0});
    set<pair<int, int>> seen;
    unordered_map<char, pair<int, int>> dir;
    dir['N'] = {0, 1};
    dir['S'] = {0, -1};
    dir['E'] = {1, 0};
    dir['W'] = {-1, 0};
    int curr = 0;

    while (!queue.empty()) {
        auto [row, col] = queue.front(); queue.pop();
        // cout << row << " " << col << endl;
        if (row < -1000 || col < -1000 || row > 1000 || col > 1000) {
            cout << "NO\n";
            return;
        }
        if (row == a && col == b) {
            cout << "YES\n";
            return;
        }
        if (curr == 0 && seen.find({row, col}) != seen.end()) {
            cout << "NO\n";
            return;
        }

        if (curr == 0) seen.insert({row, col});
        queue.push({dir[s[curr]].first + row, dir[s[curr]].second + col});
        curr = (curr+1)%n;
        
    }

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}