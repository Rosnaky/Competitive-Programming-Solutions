#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("maxcross.in", "r", stdin); freopen("maxcross.out", "w", stdout);

    int n, k, b;
    cin >> n >> k >> b;
    vector<int> prefix(n+1);

    for (int i = 0; i < b; i++) {
        int temp; cin >> temp;
        prefix[temp] = 1;
    }
    for (int i = 1; i <= n; i++) {
        prefix[i] += prefix[i-1];
    }

    long long ans = 1e15;

    for (int i = 1; i <= n-k; i++) {
        ans = min(ans, (long long)prefix[i+k]-prefix[i]);
    }
    cout << ans;
}