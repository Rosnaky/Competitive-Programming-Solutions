#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    vector<string> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << m); mask++) {
        int curr = m;
        for (int j = 0; j < n; j++) {
            int temp = 0;
            for (int i = 0; i < m; i++) {
                if (mask & (1 << i) && nums[j][m-i-1] == 'T') {
                    temp++;
                }
                else if ((!mask) & (1 << i) && nums[j][m-i-1] == 'F') {
                    temp++;
                } 
            }
            curr = min(temp, curr);
        }
        ans = max(ans, curr);
    }
    cout << ans;
}