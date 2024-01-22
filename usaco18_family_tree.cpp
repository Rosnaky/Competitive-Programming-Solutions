#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("family.in", "r", stdin);
    freopen("family.out", "w", stdout);

    map<string, string> par;

    int n; cin >> n;
    string a, b; cin >> a >> b;
    for (int i = 0; i < n; i++) {
        string x, y; cin >> x >> y;

        par[y] = x;
    }

    if (par[a] == par[b]) {
        cout << "SIBLINGS";
        return 0;
    }
    
}