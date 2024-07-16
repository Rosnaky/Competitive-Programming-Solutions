#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, c; cin >> n >> m >> c;

    vector<int> a(n), b(m);
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;

    int steps = n - m + 1;

    vector<int> prefix(n+1);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1] + ( i > m ? 0 : b[i-1]);
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        // cout << a[i] << " " << prefix[i+1] << " " << prefix[max(0, i-steps)] << endl;
        ans[i] = (a[i] + prefix[i+1] - prefix[max(0, i-steps+1)]) % c;
    }

    for (int i : ans) cout << i << " ";

    
}