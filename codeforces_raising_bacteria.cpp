#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int ans = 0;

    while (n != 0) {
        if (n%2 == 1) {
            ans++;
            n--;
        }
        else {
            n/=2;
        }
    }
    cout << ans;
}