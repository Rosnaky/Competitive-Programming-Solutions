#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k, q; cin >> n >> k >> q;

    vector<vector<int>> arr(n, vector<int>(k));
    for (vector<int> &v: arr) {
        for (int &i : v) {
            cin >> i;
        }
    }

    // int curr_max = 0, curr_min = 1e9;
    // for (int i = 1; i < n; i++) {
    //     for (int j = 0; j < k; j++) {
    //         arr[i][j] |= arr[i-1][j];
    //         curr_max = max(curr_max, arr[i][j]);
    //         curr_min = min(curr_min, arr[i][j]);
    //     }
    // }

    while (q--) {
        int m; cin >> m;
        // set<int> ans;
        vector<vector<int>> regionLimits(k, {0, (int)2e9 + 1});
        while (m--) {

            int r, c; char o; cin >> r >> o >> c;
            r--;
            if (o == '>') {
                regionLimits[r][0] = max(regionLimits[r][0], c);
            }
            else {
                regionLimits[r][1] = min(regionLimits[r][1], c);
            }
        }

        // bool good = 0;
        // for (int i = 0; i < n; i++) {
        //     if (arr[i][k-1] > regionLimits[k-1][0] && arr[i][k-1] < regionLimits[k-1][1]) {
        //         cout << i + 1 << '\n';
        //         good = 1;
        //         break;
        //     }
        // }
        // if (!good) cout << -1 << '\n';

        set<int> ans;
        for (int i = 0; i < n; i++) ans.insert(i);

        for (int r = 0; r < k; r++) {
            for (int i = 0; i < n; i++) {
                if (ans.find(i) == ans.end()) continue;
                if (r) arr[i][r] |= arr[i][r-1];
                if (arr[i][r] > regionLimits[r][0] && arr[i][r] < regionLimits[r][1]) {
                    ans.erase(i);
                    continue;
                }
            }
        }

        if (ans.size()) cout << *ans.begin() << '\n';
        else cout << -1 << '\n';

    }

}