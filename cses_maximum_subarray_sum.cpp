#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

int main() {

    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<long long> prefix(n+1);

    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        prefix[i] = prefix[i-1]+a;
    }

    ll maxSub = prefix[1];
    ll minSub = prefix[0];
    for (int i = 1; i <= n; i++) {
        maxSub = max(maxSub, prefix[i] - minSub);
        minSub = min(minSub, prefix[i]);
    }

    cout << maxSub;

}