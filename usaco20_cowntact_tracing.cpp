#include <vector>
#include <algorithm>
#include <iostream>
#include <string>


using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("tracing.in", "r", stdin);
    // freopen("tracing.out", "w", stdout);

    int n, t; cin >> n >> t;
    string s; cin >> s;

    vector<pair<int, int>> events(251);
    for (int i = 0; i < t; i++) {
        int t, x, y; cin >> t >> x >> y;
        events[t] = {--x, --y};
    }

    int zero = 0;
    for (int i = 0; i < n; i++) {
        bool good = true;
        for (int j = 0; j < 251; j++) {
            
        }
    }

}