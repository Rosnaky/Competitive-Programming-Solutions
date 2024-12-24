#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int factorial(int n) {
    if (!n) return 1;
    return n*factorial(n-1);
}

void solve() {
    int n, d; cin >> n >> d;

    cout << "1 ";
    if (n >= 3) {
        cout << "3 ";
    }
    else {
        int curr = factorial(n);

        if ((d*curr)%3 == 0) {
            cout << "3 ";
        }
    }

    if (d==5) {
        cout << "5 ";
    }

    if (d == 7 || n >= 3) cout << "7 ";

    if (d == 9 || n >= 6) cout << "9";
    else if (d == 3 && n >= 3) cout << "9";
    else if (d == 6 && n >= 3) cout << "9";
    cout << '\n';

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}