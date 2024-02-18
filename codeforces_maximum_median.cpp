#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;


int last_true(int lo, int hi, function<bool(int)> f) {
    lo--;
    while (lo < hi) {
        int mid = lo + (hi-lo+1)/2;
        if (f(mid)) lo = mid;
        else hi = mid-1;
    }
    return lo;
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (int& i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    cout << last_true(1, 2e9, [&](int x) {
        long long ops = 0;
        for (int i = (n-1)/2; i < n; i++) {
            ops += max(0, x-arr[i]);
        }
        return ops <= k;
    });
}