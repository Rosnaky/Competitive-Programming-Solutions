#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;

    vector<int> arr(n);
    for (int& i : arr) cin >> i;


    vector<int> diff(n+1);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        l--;
        r--;
        diff[l]++;
        diff[r+1]--;
    }

    vector<int> cnt(n);
    int curr = 0;
    for (int i = 0; i < n; i++) {
        curr += diff[i];
        cnt[i] = curr;
    }

    sort(cnt.begin(), cnt.end());
    sort(arr.begin(), arr.end());
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (ll) arr[i]*cnt[i];
    }

    cout << ans;
}