#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("family.in", "r", stdin);
    freopen("family.out", "w", stdout);

    int n; cin >> n;
    unordered_map<string, int> cti;
    vector<int> parent(10000, -1);
    // for (int i = 0; i < n; i++) {
    //     string s; cin >> s;
    //     cti[s] = i;
    // }
    string a, b; cin >> a >> b;
    cti[a] = 0, cti[b] = 1;
    int ctii = 2;

    for (int i = 0; i < n; i++) {
        string x, y; cin >> x >> y;

        if (!cti.count(x)) {
            cti[x] = ctii;
            ctii++;
        }
        if (!cti.count(y)) {
            cti[y] = ctii;
            ctii++;
        }

        parent[cti[y]] = cti[x];
    }

    if (parent[0] == parent[1]) {
        cout << "SIBLINGS\n";
        return 0;
    }


    int dist = 0, curr = 0;
    while (parent[curr] != -1) {
        curr = parent[curr];
        dist++;
        if (curr == 1) break;
    }

    if (curr == 1) {
        string ans = (dist > 1 ? "grand-" : "") + (string)"mother";
        for (int i = 0; i < dist - 2; i++) {
            ans = "great-" + ans;
        }
        cout << b + " is the " + ans + " of " + a + "\n";
        return 0;
    }

    dist = 0, curr = 1;
    while (parent[curr] != -1) {
        curr = parent[curr];
        dist++;
        if (curr == 0) break;
    }

    if (curr == 0) {
        string ans = (dist > 1 ? "grand-" : "") + (string)"mother";
        for (int i = 0; i < dist - 2; i++) {
            ans = "great-" + ans;
        }
        cout << a + " is the " + ans + " of " + b + "\n";
        return 0;
    }

    dist = 0, curr = 0;
    bool found = false;
    while (parent[curr] != -1) {
        curr = parent[curr];
        dist++;
        if (parent[1] == curr) {
            found = true;
            break;
        }
    }

    if (found) {
        string ans = "aunt";
        for (int i = 0; i < dist - 2; i++) {
            ans = "great-" + ans;
        }
        cout << b + " is the " + ans + " of " + a + "\n";
        return 0;
    }

    dist = 0, curr = 1;
    found = false;
    while (parent[curr] != -1) {
        curr = parent[curr];
        dist++;
        if (parent[0] == curr) {
            found = true;
            break;
        }
    }

    if (found) {
        string ans = "aunt";
        for (int i = 0; i < dist - 2; i++) {
            ans = "great-" + ans;
        }
        cout << a + " is the " + ans + " of " + b + "\n";
        return 0;
    }

    int curr1 = 0, curr2 = 1;
    while (parent[curr2] != -1) {
        curr2 = parent[curr2];
    }
    while (parent[curr1] != -1) {
        curr1 = parent[curr1];
    }

    if (curr1 == curr2) {
        cout << "COUSINS\n";
        return 0;
    }

    cout << "NOT RELATED\n";


}