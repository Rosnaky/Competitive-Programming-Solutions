#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


void solve() {

    int n; cin >> n;
    vector<long long> prefix(n+1);
    string s;

    for (int i = 1; i <= n; i++) {
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
    }
    cin >> s;

    long long ans = 0;
    int right = n-1;
    while (right >= 0 && s[right] != 'R') right--;
    
    for (int left = 0; left < right; left++) {

        if (s[left] != 'L') continue;

        ans += prefix[right+1] - prefix[left];
        right--;
        while (right >= 0 && s[right] != 'R') right--;
    }

    cout << ans << "\n";

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}