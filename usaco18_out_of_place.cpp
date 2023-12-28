#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    int n;
    cin >> n;

    int b = -1;
    
    vector<int> order(n);
    vector<int> correct(n);


    for (int i = 0; i < n; i++) {
        cin >> order[i];
        correct[i] = order[i];
    }

    sort(correct.begin(), correct.end());

    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (order[i] != correct[i]) {
            ans++;
        }
    }
    cout << ans << "\n";
}