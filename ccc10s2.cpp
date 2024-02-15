#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;


int main() {

    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    map<string, string> count;
    for (int i = 0; i < n; i++) {
        string s, c; cin >> c >> s;
        
        count[s] = c;
    }

    string s, ans = "", curr = ""; cin >> s;

    for (int i = 0; i < s.size(); i++) {
        curr += s[i];
        if (count.count(curr)) {
            ans += count[curr];
            curr = "";
        }
    }

    cout << ans;
}