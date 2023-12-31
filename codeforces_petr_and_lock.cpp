#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;


    for (int mask = 0; mask < (1 << n); mask++) {
        int curr = 0;
        for (int i = 0; i < n; i++) {
            if (mask&(1<<i)) {
                curr+=a[i];
            }
            else {
                curr-=a[i];
            }
        }
        if (!(curr%360)) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}