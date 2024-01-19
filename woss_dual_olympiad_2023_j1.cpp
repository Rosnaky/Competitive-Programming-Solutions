#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        ans = min(ans ,temp);
    }
    cout << ans;
}