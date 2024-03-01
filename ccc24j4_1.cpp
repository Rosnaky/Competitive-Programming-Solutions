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
        int x = -1, y = -1, z;
        for (int c = 0; c < a.size(); c++) {
            if (a[c] != b[c]) {
                if (x == -1) x = c;
                else if (y == -1) y = c;
                else z = c;
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

        temp = "";
        for (char c : s) {
            if (c == z) continue;
            else if (c == y) temp+=char(x);
            else temp+=c;
        }

        if (temp == t) {
            cout << char(y) << " " << char(x) << "\n" << char(z); 
            return 0;
        }


        temp = "";
        for (char c : s) {
            if (c == y) continue;
            else if (c == x) temp+=char(z);
            else temp+=c;
        }

        if (temp == t) {
            cout << char(x) << " " << char(z) << "\n" << char(y); 
            return 0;
        }

        temp = "";
        for (char c : s) {
            if (c == y) continue;
            else if (c == z) temp+=char(x);
            else temp+=c;
        }

        if (temp == t) {
            cout << char(z) << " " << char(x) << "\n" << char(y); 
            return 0;
        }


        temp = "";
        for (char c : s) {
            if (c == x) continue;
            else if (c == z) temp+=char(y);
            else temp+=c;
        }

        if (temp == t) {
            cout << char(z) << " " << char(y) << "\n" << char(x); 
            return 0;
        }

        temp = "";
        for (char c : s) {
            if (c == x) continue;
            else if (c == y) temp+=char(z);
            else temp+=c;
        }

        if (temp == t) {
            cout << char(y) << " " << char(z) << "\n" << char(x); 
            return 0;
        }
        
    }
}