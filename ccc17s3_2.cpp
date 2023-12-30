#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int> nums(2001);
    for (int i = 0; i < n; i++) {
        int curr;
        cin >> curr;
        nums[curr]++;
    }

    // set<pair<int, int>> pairs;
    vector<int> sums(4001);

    int length = 0;
    int times = 0;

    for (int i = 0; i < 2000; i++) {
        for (int j = i; j <= 2000; j++) {
            if (i == j) sums[i+j] = nums[i]/2;
            else sums[i+j] = min(nums[i], nums[j]);
        }
    }

    for (int i : sums) {
        if (i > length) {
            length = i;
            times = 1;
        }
        else if (i == length) {
            times++;
        }
    }

    cout << length << " " << times;
}