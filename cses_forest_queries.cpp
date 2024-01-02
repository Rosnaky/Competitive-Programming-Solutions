#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> prefix(n+1, vector<int>(n+1));

    for (int i = 1; i<=n; i++) {
        string temp; cin >> temp;
        for (int j = 1; j<=n;j++) {
            prefix[i][j] = prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+(temp[j-1]=='*');
        }
    }

    for (int i = 0; i < q; i++) {
        int x1, x2, y1, y2;
        cin >> y1 >> x1 >> y2 >> x2;

        int ans = prefix[y2][x2] - prefix[y2][x1-1] - prefix[y1-1][x2] + prefix[y1-1][x1-1];
        cout << ans << "\n";
    }
}