#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    int n; cin >> n;
    vector<int> a(n);
    for (int& i : a) {cin >> i; i--;}

    vector<int> order(n);
    for (int& i : order) cin >> i;

    for (int i = 0; i < 3; i++) {
        vector<int> temp(n);
        for (int j = 0; j < n; j++) {
            temp[j] = order[a[j]];
        }
        order = temp; 
    }
    for (int& i : order) cout << i << "\n";
}