#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n; cin >> n;

    vector<ll> prefix(n+1);

    for (int i = 1; i <= n; i++) {
        int temp; cin >> temp;
        prefix[i] = prefix[i-1]+temp;
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j++) {
            if ((prefix[j]-prefix[i-1])%7 == 0 && (prefix[j]-prefix[i])!=0) {
                ans = max(ans, j-i+1);
            }
        }
    }
    cout << ans;
}