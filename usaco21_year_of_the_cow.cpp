#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    // freopen("whereami.in", "r", stdin);
    // freopen("whereami.out", "w", stdout);

    int n; cin >> n;

    unordered_map<string, int> cows, signs;
    unordered_map<string, string> cowsign;
    
    signs["Ox"] = 0;
    signs["Tiger"] = 1;
    signs["Rabbit"] = 2;
    signs["Dragon"] = 3;
    signs["Snake"] = 4;
    signs["Horse"] = 5;
    signs["Goat"] = 6;
    signs["Monkey"] = 7;
    signs["Rooster"] = 8;
    signs["Dog"] = 9;
    signs["Pig"] = 10;
    signs["Rat"] = 11;


    cows["Bessie"] = 0;
    cowsign["Bessie"] = "Ox";

    for (int i = 0; i < n; i++) {
        string a, x, t, b;
        cin >> a >> x >> x >> x >> t >> b >> b >> b;
    
        cows[a] = x == "next" ? 12*(signs[t] <= signs[cowsign[b]]) + signs[t]-signs[cowsign[b]] + cows[b] : cows[b] - (12*(signs[t] >= signs[cowsign[b]]) - signs[t]+signs[cowsign[b]]);
        cowsign[a] = t;
    }

    // for (auto p : cows) {
    //     cout << p.first << " " << p.second << "\n";
    // }
    
    cout << abs(cows["Bessie"] - cows["Elsie"]);
}