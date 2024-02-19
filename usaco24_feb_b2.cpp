#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int n, m;
vector<int> arr;

int res(bool a, bool b, bool c, int i, int j, int k) {
    if (a == c) {
        if (!a) return min(arr[i], arr[j]);
        return min(arr[j], arr[k]);
    }
    if (a != c && c) return max(arr[k], arr[j]);
    return max(0, arr[j]-m);
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    string s; cin >> s;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }

    ll ans = 0;
    if (n > 2) ans += res(s[n-1] == 'L', s[0] == 'L', s[1] == 'L', n-1, 0, 1);
    for (int i = 1; i < n-1; i++) {

        ans += res(s[i-1] == 'L', s[i] == 'L', s[i+1] == 'L', i-1, i, i+1);
    }
    if (n > 2) ans += res(s[n-2] == 'L', s[n-1] == 'L', s[0] == 'L', n-2, n-1, 0);

    cout << ans;

}