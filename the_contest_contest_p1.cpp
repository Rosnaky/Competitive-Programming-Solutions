#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    string s; cin >> s;

    vector<bool> states(n);
    vector<int> prefix(n+1);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1] + (s[i-1] == 'Y'); 
        states[i-1] = s[i-1] == 'Y';
    }

    int curr = prefix[n];
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int c = prefix[j]-prefix[i];
            if (c < n && c >= 0 && !states[c]) {
                states[c] = true;
                curr++;
            }

            cout << i << " " << j << " " << c <<  " " << curr << endl;

            if (curr > n/2.0) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
}