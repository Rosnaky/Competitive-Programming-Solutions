#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);


    int n, q; cin >> n >> q;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());

    while (q--) {
        int x, y; cin >> x >> y;

        int a, mid;
        int l = 0, r = n;
        while (l < r) {
            mid = (r+l)/2;
            // cout << l << " " << r << " " << mid << endl;
            if (arr[mid] < x) {
                l = mid+1;
            }
            else {
                r = mid;
            }
        }
        a = l;

        // cout << a << endl << endl;

        l = 0, r = n;
        while (l < r) {
            mid = (r+l)/2;
            // cout << l << " " << r << " " << mid << endl;
            if (arr[mid] < y) {
                l = mid+1;
            }
            else {
                r = mid;
            }
        }
        int b = l - (l >= n || arr[l] > y);

        cout << b-a+1 << "\n";
    }
}