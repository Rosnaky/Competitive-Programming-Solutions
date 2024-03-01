#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s, t; cin >> s >> t;

    vector<int> a(256);
    vector<int> b(256);

    for (int c : s) a[c]++;
    for (int c : t) b[c]++;

    if (s.size() == t.size()) {

        for (int c : s) {
            if (a[c] != b[c]) {
                for (int i = 0; i < a.size(); i++) {
                    if (a[c] == b[i] && b[i] != a[i]) {
                        cout << char(c) << " " << char(i) << "\n-";
                        return 0;
                    }
                }
            }
        }
    }

    else {
        int x = -1, y, z;
        for (int c = 0; c < a.size(); c++) {
            if (a[c] != b[c]) {
                for (int i = 0; i < a.size(); i++) {
                    if (a[c] == b[i] && b[i] != a[i]) {
                        if (x == -1) {
                            x = c, y = i;
                        }
                        else if (x != c) z = c;
                    }
                }
                cout << char(c) << " " << char(x) << " " << char(y) << " " << char(z) << endl;
            }
        }

        string temp = "";
        for (char c : s) {
            if (c == z) continue;
            else if (c == x) temp+=char(y);
            else temp+=c;
        }

        if (temp == t) {
            cout << char(x) << " " << char(y) << "\n" << char(z); 
            return 0;
        }

        cout << char(z) << " " << char(y) << "\n" << char(x);
        
    }
}