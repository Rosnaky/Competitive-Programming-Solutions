#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;


void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for (vector<int>& v : arr) {
        string s; cin >> s;

        for (int i = 0; i < m; i++) {
            v[i] = s[i]-'0';
        }
    }

    int ans = 0;
    for (int layer = 0; layer < min(n/2, m/2); layer++) {
        int left = layer, top = layer, right = m-layer-1, bottom = n-layer-1;
        int width = right - left+1, height = bottom-top+1;
        // cout << layer << ": " << left << " " << right << " | " << top << " " << bottom << " | " << width << " " << height << endl; //* remove

        int curr = 0;
        pair<int, int> pos = {top, left};

        for (int i = 0; i < width*2 + height*2 - 1; i++) {
            // cout << pos.first << " " << pos.second << endl; //* remove
            curr *= 10; curr += arr[pos.first][pos.second];
            curr %= 10000;
            if (curr == 1543) ans++;

            // cout << curr << endl; //* remove

            if (pos.first == top && pos.second != right) pos.second++;
            else if (pos.second == right && pos.first != bottom) pos.first++;
            else if (pos.first == bottom && pos.second != left) pos.second--;
            else if (pos.second == left && pos.first != top) pos.first--;
        }
    }

    cout << ans << '\n';


}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

/*
1
4 4
5431
1435
5518
7634
*/