#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int w; cin >> w;
    int n; cin >> n;

    vector<int> cars(n);
    for (int i = 0; i < n; i++) {
        cin >> cars[i];
    }

    int l = 0, sum = 0, ans = 0;

    while (l < n) {
        sum += cars[l];
        if (l >= 4) sum -= cars[l-4];

        if (sum > w) {
            break;
        }

        ans++;
        l++;
    }

    cout << ans;
}