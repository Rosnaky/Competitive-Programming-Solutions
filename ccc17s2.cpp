#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);
    
    for (int& a : nums) cin >> a;

    sort(nums.begin(), nums.end());

    priority_queue<int> lows;
    priority_queue<int> highs;

    for (int i = 0; i < ceil(n/2.0); i++) {
        lows.push(nums[i]);
    }
    for (int i = ceil(n/2.0); i < n; i++) {
        highs.push(-nums[i]);
    }

    while (!lows.empty() && !highs.empty()) {
        cout << lows.top() << " "; lows.pop();
        cout << highs.top()*-1 << " "; highs.pop();
    }
    if (!lows.empty()) cout << lows.top();
}