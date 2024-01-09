#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("circlecross.in", "r", stdin); freopen("circlecross.out", "w", stdout);

    string s; cin >> s;
    int n = s.size();

    vector<pair<int, int>> nums;

    for (char c = 'A'; c <= 'Z'; c++) {
        int first = -1, second;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                if (first == -1) {
                    first = i;
                }
                else {
                    second = i; break;
                }
            }
        }

        nums.push_back({first, second});
    }


    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (nums[i].first < nums[j].first && nums[i].second < nums[j].second && nums[j].second > nums[i].first && nums[i].second > nums[j].first) {
                ans++;
                // cout << i << " " << j << endl;
            }
        }
    }
    cout << ans;
}