#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int k, n; cin >> k >> n;

    vector<int> a(k), b(n);

    cin >> a[0];
    for (int i = 1; i < k; i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    for (int &i : b) cin >> i;
    

    unordered_set<int> possible;

    for (int i : a) {
        possible.insert(b[0] - i);
    }

    int ans = 0;

    for (int i : possible) {
        unordered_set<int> points;
        for (int j : a) {
            points.insert(i+j);
        }

        bool valid = true;
        for (int p : b) {
            valid &= points.count(p);
        }

        ans += valid;

    }

    cout << ans;

}