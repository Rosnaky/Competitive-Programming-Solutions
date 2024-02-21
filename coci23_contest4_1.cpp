#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.in", "r", stdin);

    int n; cin >> n;
    vector<pair<string, vector<vector<int>>>> players;
    while  (n--) {
        string s; cin >> s;
        vector<vector<int>> grid(5, vector<int>(5));
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> grid[i][j];
            }
        }
        players.push_back({s,grid});
    }

    int m; cin >> m;
    vector<bool> nums(91);
    while (m--) {
        int a; cin >> a;
        nums[a] = true;
    }

    vector<string> winners;

    for (auto p : players) {
        bool good = true;
        for (int i = 0; i < 5; i++) {
            good = true;
            for (int j = 0; j < 5; j++) {
                if (!nums[p.second[i][j]]) {
                    good = false;
                    break;
                } 
            }
            if (good) {
                winners.push_back(p.first);
                break;
            }

            good = true;
            for (int j = 0; j < 5; j++) {
                if (!nums[p.second[j][i]]) {
                    good = false;
                    break;
                } 
            }
            if (good) {
                winners.push_back(p.first);
                break;
            }
        }

        if (good) continue;
        for (int i = 0; i < 5; i++) {
            if (!nums[p.second[i][i]]) {
                good = false;
                break;
            } 
        }

        if (good) {winners.push_back(p.first); continue;}
        
        
        good = true;
        for (int i = 0; i < 5; i++) {
            if (!nums[p.second[i][4-i]]) {
                good = false;
                break;
            } 
        }

        if (good) winners.push_back(p.first);
    }

    cout << winners.size() << "\n";
    for (string s : winners) cout << s << "\n";
}