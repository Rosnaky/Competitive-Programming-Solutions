#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);


    map<char, int> base;
    base['I'] = 1;
    base['V'] = 5;
    base['X'] = 10;
    base['L'] = 50;
    base['C'] = 100;
    base['D'] = 500;
    base['M'] = 1000;

    string s; cin >> s;
    int right = s.size()-1;
    int prev = 0;
    long long ans = 0;


    while (right > 0) {
        int temp = (s[right-1]-'0') * base[s[right]];

        if (base[s[right]] < prev) {
            ans -= temp;
        }
        else {
            ans += temp;
        }

        prev = base[s[right]];

        right-=2;
    }

    cout << ans;
}