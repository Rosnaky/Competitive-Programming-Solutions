#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
#define mod int(1e9+7);

int n;
int target;


int dp(int curr, int left) {
    // cout << left << " " << target << endl;
    if (curr == n && left == target) {
        return 1;
    }
    if (curr == n) return 0;

    curr++;
    return (dp(curr, left+curr) + dp(curr, left))%mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    target = n*(n+1)/4;

    if (target*2 % 2 != 0) {cout << 0; return 0;}

    cout << dp(1, 1);
}