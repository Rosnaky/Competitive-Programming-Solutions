#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    vector<pair<int, int>> farms(n);

    vector<int> open(int(1e6+5)), times(int(1e6+5));
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        farms[i].second = x;
        open[x]++;
    }
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        farms[i].first = x;
        times[x]++;
    }

    sort(farms.begin(), farms.end());
    open[0] = n;
    for (int i = 1; i <= open.size(); i++) {
        open[i] = open[i-1]-open[i];
        times[i] += times[i-1];
    }

    for (int i = 0; i < 14; i++) {
        cout << open[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 14; i++) {
        cout << times[i] << " ";
    }
    cout << endl;

    
    while (q--) {

        int v, s; cin >> v >> s;
        if (open[times[s]+s+v] >= v) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
}