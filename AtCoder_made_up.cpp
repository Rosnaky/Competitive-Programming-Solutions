#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    unordered_map<int, int> a;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        a[temp]++;
    }

    vector<int> b(n);
    for (int & i : b) cin >> i;

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int c; cin >> c;

        ans += a[b[--c]];
    }

    cout << ans;

}