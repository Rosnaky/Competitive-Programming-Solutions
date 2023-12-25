#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    bool dp[101001] = {0};
    int sum = 0, x;
    dp[0] = true;

    while (n--) {
        cin >> x;
        sum += x;

        for (int i = sum; i >= x; i--) dp[i] |= dp[i-x];
    }

    vector<int> v;
    for (int i = 1; i <= sum; i++) if(dp[i]) v.push_back(i);

    cout << v.size() << "\n";
    for (int x : v) cout << x << " ";
}