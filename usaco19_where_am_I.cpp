#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int n; string s;
    cin >> n >> s;

    unordered_map<string, int> umap;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n-i; j++) {
            umap[s.substr(i, j)]++;
        }
    }

    int ans = 0;
    for (auto p : umap) {
        // cout << p.first << " " << p.second << endl;
        if (!--p.second) continue;
        ans = p.first.size()+1 > ans ? p.first.size()+1 : ans;
    }

    cout << ans;
}