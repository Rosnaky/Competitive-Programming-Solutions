#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <string>
#pragma GCC target("popcnt")

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        string temp; cin >> temp;
        for (int j = 0; j < n; j++) {
            grid[i][j] = temp[j]-'0';
        }
    }

    vector<bitset<3001>> bit(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bit[i][j] = grid[j][i];
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            long long cnt = (bit[i]&bit[j]).count();
            ans += cnt*(cnt-1)/2;
        }
    }
    cout << ans;



    // int n;
    // cin >> n;
    // vector<vector<int>> grid(n, vector<int>(n, 0));
    // for (int i = 0; i < n; i++) {
    //     string s;
    //     cin >> s;
    //     for (int j = 0; j < n; j++) {
    //         grid[i][j] = s[j] - '0';
    //     }
    // }
    // vector<bitset<3000>> bit(n);
    // for (int j = 0; j < n; j++) {
    //     for (int i = 0; i < n; i++) {
    //         bit[j][i] = grid[i][j];
    //     }
    // }
    // int ans = 0;
    // for (int i = 0; i < n; i++) {
    //     for (int j = i + 1; j < n; j++) {
    //         int cnt = (bit[i] & bit[j]).count();
    //         ans += cnt * (cnt - 1) / 2;
    //     }
    // }
    // cout << ans << endl;
    // return 0;

    
}