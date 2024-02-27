#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;

    while (n--) {
        string s; cin >> s;
        
        string temp = "";
        int i = 1;
        while (isdigit(s[i])) {
            temp += s[i];
            i++;
        }

        string temp1 = "";
        i++;
        while (i < s.size()) {
            temp1 += s[i];
            i++;
        }
        long long col = stoi(temp1);
        string ans = "";
        while (col > 0) {
            ans += (col%26)+'A';
            col /= 26;
        }

        for (int j = ans.size(); j >= 0; j--) cout << ans[j];

        cout << 'C' << temp << "\n";
    }

}