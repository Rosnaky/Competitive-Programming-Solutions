#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>

using namespace std;


set<string> ans;
string s;


void backtrack(string curr, vector<bool>& seen) {
    if (curr.size() == s.size()) {
        ans.insert(curr);
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        if (seen[i]) continue;
        string temp = curr+s[i];
        seen[i] = true;
        backtrack(temp, seen);
        seen[i] = false;
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;

    vector<bool> seen(s.size());
    backtrack("", seen);

    cout << ans.size() << "\n";
    for (string a : ans) {
        cout << a << "\n";
    }
}