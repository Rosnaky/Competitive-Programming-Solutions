#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


void solve() {

    long long n; cin >> n;

    cout << (n+1)*(n+1)+1 << "\n";

}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}