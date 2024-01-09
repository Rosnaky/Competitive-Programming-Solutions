#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);

    int n; cin >> n;

    vector<set<string>> nums(n);

    for (int i = 0; i < n; i++) {
        string name; int k;
        cin >> name >> k;
        for (int j = 0; j < k; j++) {
            string c; cin >> c;
            nums[i].insert(c);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int temp = 0;
            for (string e : nums[i]) {
                if (nums[j].count(e)) temp++;
            }
            ans = max(temp, ans);
        }
    }
    cout << ans+1;
}