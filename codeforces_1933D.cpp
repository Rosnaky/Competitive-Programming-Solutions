#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;


void solve() {

    int n; cin >> n;
    vector<int> arr(n);
    
    unordered_map<int, int> count;

    int mn = 1e9;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        arr[i] = a;
        count[a]++;
        mn = min(mn, a);
    }

    if (count[mn] == 1) {cout << "yes\n"; return;}
    else {
        for (int i = 0; i < n; i++) {
            if (arr[i]%mn != 0) {cout << "yes\n"; return;}
        }
    }
    cout << "no\n";
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}