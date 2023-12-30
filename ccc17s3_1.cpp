#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int> lengths(n);
    for (int& i : lengths) cin >> i;

    vector<bool> seen;

    int ans = 0;
    int ansSize = 0;
    for (int s = 0; s <= 4000; s++) {
        int temp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (lengths[i] + lengths[j] == s) {
                    temp++;
                }
            }
        }
        if (temp > ans) {
            ans = temp;
            ansSize = 1;
        }
        else if (temp == ans) {
            ansSize++;
        }
    }

    cout << ans << " " << ansSize;
}