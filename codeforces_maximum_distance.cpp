#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            ans = max(ans, (long long) (pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2)));
        }
    }
    cout << ans;
}