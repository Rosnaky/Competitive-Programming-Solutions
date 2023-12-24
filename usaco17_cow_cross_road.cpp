#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);

    int c, n;
    cin >> c >> n;

    multiset<int> chickens;
    vector<pair<int, int>> cows;
    
    for (int i = 0; i < c; i++) {
        int num;
        cin >> num;
        chickens.insert(num);
    }

    for (int i = 0; i < n; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        cows.push_back({temp2, temp1});
    }

    sort(cows.begin(), cows.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = chickens.lower_bound(cows[i].second);
        
        if (it == chickens.end()) continue;
        
        if (*it <= cows[i].first) {
            ans++;
            chickens.erase(it);
        }
    }
    cout << ans;
}