#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("blocks.in", "r", stdin); freopen("blocks.out", "w", stdout);

    int n; cin >> n;

    vector<int> ans(26);

    for (int i = 0; i < n; i++) {
        string s1, s2; cin >> s1 >> s2;
        
        vector<int> temp1(26), temp2(26);

        for (char c : s1) {
            temp1[c-'a']++;
        }
        for (char c : s2) {
            temp2[c-'a']++;
        }

        for (int c = 0; c < 26; c++) {
            ans[c] += max(temp1[c], temp2[c]);
        }
    }

    for (int a : ans) cout << a << "\n";

}