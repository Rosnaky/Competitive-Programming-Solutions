#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

vector<int> nums;
int n;
ll ans(int i, ll left, ll right) {
    if (i == n) return abs(right-left);

    return min(ans(i+1, left+nums[i], right), ans(i+1, left, right+nums[i]));
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        nums.push_back(temp);
    }

    cout << ans(0, 0, 0);
}