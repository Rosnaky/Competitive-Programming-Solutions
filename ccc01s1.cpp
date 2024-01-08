#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, vector<char>> nums;

int count(char tok) {
    int ans = 0;
    for (char c : nums[tok]) {
        if (c == 'K') ans += 3;
        else if (c=='A') ans+= 4;
        else if (c=='Q') ans+=2;
        else if (c=='J') ans+=1;
    }
    if (nums[tok].size() == 0) ans += 3;
    else if (nums[tok].size() == 1) ans += 2;
    else if (nums[tok].size() == 2) ans += 1;
    return ans;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    char tok;
    string s; cin >> s;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == 'C' || c == 'H' || c == 'S' || c == 'D') {
            tok = c; continue;
        }

        nums[tok].push_back(c);
    }

    cout << "Cards Dealt      Points";
    cout << "\nClubs    " << count('C');
    cout << "\nDiamonds    " << count('D');
    cout << "\nHearts    " << count('H');
    cout << "\nSpades    " << count('S');
    cout  << "\nTotal " << count('C')+count('D')+count('H')+count('S');

}