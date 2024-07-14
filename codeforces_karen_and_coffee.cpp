#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k, q; cin >> n >> k >> q;

    vector<int> a(200001);
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        a[l]++;
        a[r+1]--;
    }

    vector<int> pre(200001);
    int tot = 0;
    for (int i = 0; i < pre.size(); i++) {
        tot += a[i];
        pre[i] = tot;
    }

    vector<int> ans(200001);
    int curr = 0;
    for (int i = 0; i < pre.size(); i++) {
        curr += pre[i] >= k;
        ans[i] = curr;
    }


    while (q--) {
        int l, r; cin >> l >> r;
        int curr = ans[r]-ans[l-1];
        cout << curr << '\n';
    }

}