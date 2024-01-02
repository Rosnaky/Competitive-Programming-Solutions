#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<string> first(n);
    for (int i = 0; i < n; i++) {
        cin >> first[i];
    }

    map<string, string> partners;

    for (int i = 0; i < n; i++) {
        string second;
        cin >> second;

        if (partners.count(first[i]) && (partners[first[i]] != second || partners[first[i]] == first[i])) {
            cout << "bad";
            return 0;
        }
        if (partners.count(second) && (partners[second] != first[i] || partners[second] == second)) {
            cout << "bad";
            return 0;
        }
        if (first[i] == second) {
            cout << "bad";
            return 0;
        }

        partners[first[i]] = second;
        partners[second] = first[i];
    }

    cout << "good";
}