#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;


bool prime(int a) {
    for (int i = 2; i <= sqrt(a); i++) {
        if (a%i == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n; cin >> n;

    for (int i = 3; i <= n*2; i++) {
        if (!prime(i)) continue;
        int j = 2*n-i;
        if (prime(j)){
            cout << i << " " << j << "\n";
            return;
        }
    }
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}