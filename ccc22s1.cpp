#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 0;

    while (n >= 0) {
        if (n % 5 == 0) {
            ans += 1;
        }
        n -= 4;
    }

    cout << ans;
}