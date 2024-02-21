#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<int> arr(n);
    for (int &i : arr) cin >> i;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == arr[(i+n/2)%n]) ans++;
    }

    cout << ans;
}