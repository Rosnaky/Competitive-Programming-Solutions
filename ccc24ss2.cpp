#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t, n; cin >> t >> n;

    while (t--) {
        string s; cin >> s;
        map<char, int> count;

        for (char c : s) {
            count[c]++;
        }

        bool good = true;
        bool light = count[s[0]] == 1;
        for (int i = 0; i < n; i++) {
            if (light && count[s[i]] > 1) {
                good = false;
                break;
            }
            if (!light && count[s[i]] == 1) {
                good = false;
                break;
            }
            light = !light;
        }

        if (good) cout << "T\n";
        else cout << "F\n";
    }

    
}