#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 0;

    for (int i = n-1; n >= 3; n--) {
        for (int j = i-1; j >= 2; n--) {
            for (int k = j-1; k >= 1; k--) {
                ans += 1;
            }
        }
    }

    cout << ans;
}