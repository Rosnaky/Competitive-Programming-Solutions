#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);

    map<string, int> cows;
    cows["Bessie"] = 0, cows["Elsie"] = 0, cows["Daisy"] = 0, cows["Gertie"] = 0, cows["Annabelle"] = 0, cows["Maggie"] = 0, cows["Henrietta"] = 0;

    int n; cin >> n;

    while (n--) {
        string s; int a; cin >> s >> a;
        cows[s] += a;
    } 

    map<int, vector<string>> ans;
    for (auto p : cows) {
        ans[p.second].push_back(p.first);
    }

    auto it = ans.begin();
    it++;
    if (it != ans.end() && it->second.size() == 1) {
        cout << it->second[0] << "\n";
    }
    else cout << "Tie\n";
}