#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);

    int n; cin >> n;

    unordered_map<string, vector<string>> cities;
    
    int ans = 0;

    for (int i = 0; i < n; i++) {
        string a, b; cin >> a >> b;
        if (b == a.substr(0, 2)) {
            cities[b].push_back(a);
            continue;
        }
        
        for (string city : cities[a.substr(0, 2)]) {
            if (city.substr(0, 2) == b) {
                ans++;
            }
        }
        cities[b].push_back(a);
    }

    cout << ans;
}