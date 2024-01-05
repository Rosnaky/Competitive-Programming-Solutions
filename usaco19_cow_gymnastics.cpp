#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("gymnastics.in", "r", stdin); freopen("gymnastics.out", "w", stdout);

    int k, n; cin >> k >> n;

    vector<vector<int>> nums(k, vector<int>(n));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            int temp; cin >> temp;
            nums[i][temp-1] = j;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i==j) continue;
            bool valid = true;
            for (int l = 0; l < k; l++) {
                if (nums[l][i] < nums[l][j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) ans++;
        }
    }

    cout << ans;
}