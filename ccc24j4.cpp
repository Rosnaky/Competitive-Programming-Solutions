#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s, t; cin >> s >> t;

    int quiet = -1;
    int sillya = -1, sillyb = -1;
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        if (j < t.size() && s[i] != t[j]) {
            int k = i+1;
            bool isquiet = true;
            while (k < t.size()) {
                isquiet = s[k] != t[k];
                if(!isquiet) break;
                k++;
            }
            // cout << s[i] << " " << t[j] << " " << isquiet << endl;
            if (!isquiet || (quiet != -1 && s[i] != quiet)) sillya = s[i], sillyb = t[j], j++;
            else quiet = s[i];
        }
        else if (j == t.size()) {
            quiet = s[i];
            break;
        }
        else j++;
    }

    cout << char(sillya) << " " << char(sillyb) << "\n" << (quiet == -1 ? '-' : char(quiet));

}