#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x;
    cin >> x;
    map<string, vector<string>> same;
    for (int i = 0; i < x; i++) {
        string a, b;
        cin >> a >> b;
        // same[a].push_back(b);
        same[b].push_back(a);
    }

    int y;
    cin >> y;
    map<string, vector<string>> diff;
    for (int i = 0; i < y; i++) {
        string a, b;
        cin >> a >> b;
        diff[a].push_back(b);
    }

    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        string a, b, c;
        cin >> a >> b >> c;

        vector<string> group = {a, b, c};

        for (string p : group) {
            for (string s : same[p]) {
                if (find(group.begin(), group.end(), s) == group.end()) {
                    ans++;
                }
            }
            for (string s : diff[p]) {
                if (find(group.begin(), group.end(), s) != group.end()) {
                    ans++;
                }
            }
        }
    }

    cout << ans;
}