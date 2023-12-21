
#include <algorithm>
#include <iostream>
#include <cmath>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    if (a >= b) {
        cout << floor(a/b);
    }

    if (a%b != 0) {
        a %= b;
        bool skip = true;
        while (skip) {
            skip = false;
            for (int factor = 1; factor <= min(a, b); factor++) {
                if (a%factor == 0 && b%factor == 0) {
                    a /= factor;
                    b /= factor;
                    skip = true;
                }
            }
        }

        cout << " " << a << "/" << b;
    }
}