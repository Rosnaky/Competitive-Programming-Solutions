#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s; cin >> s;
    int n = s.size();

    string curr = "", num = "";
    for (int i = 0; i < n; i++) {
        if (s[i] == '+' || s[i] == '-') {
            char sign = s[i];
            i++;
            while (isdigit(s[i])) {
                num+=s[i];
                i++;
            }
            i--;

            cout << curr << " ";
            if (sign == '+') cout << "tighten ";
            else cout << "loosen ";
            cout << num << "\n";
            curr = "";
            num = "";
        }
        else {
            curr += s[i];
        }
    }
}