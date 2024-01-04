#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    vector<int> city(n);
    vector<int> tower(m);

    for (int i = 0; i < n; i++) {
        cin >> city[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> tower[i];
    }

    sort(city.begin(), city.end());
    sort(tower.begin(), tower.end());

    int c = 0, t = 0, ans = 0;
    while (c < n) {
        while (t != m-1 && abs(tower[t+1]-city[c]) <= abs(tower[t]-city[c])) {
            t++;
        }
        ans = max(ans, abs(tower[t]-city[c]));
        
        // cout << abs(tower[t]-city[c]) << " " << c << " " << t << endl;
        c++;
    }
    cout << ans;
}