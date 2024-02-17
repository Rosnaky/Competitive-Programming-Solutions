#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("firehouse.in", "r", stdin);

    int n; cin >> n;
    vector<int> houses(n);
    for (int i = 0; i < n; i++) {
        cin >> houses[i];
    }
    int k; cin >> k;

    sort(houses.begin(), houses.end());
    
}