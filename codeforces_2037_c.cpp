#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve(){

    int n; cin >> n;

    vector<int> arr(n);
    if (n <= 4) {
        cout << -1 << '\n';
        return;
    }

    for (int i = 1; i <= n; i+=2) {
        arr[(i-1)/2] = i;
    }
    int temp = arr[n/2-(n+1)%2];
    arr[n/2-(n+1)%2] = 5;
    arr[2] = temp;

    for (int i = 2; i <= n; i+=2) {
        arr[(n+n%2)/2 + i/2-1] = i;
    }

    temp = arr[(n+n%2)/2];
    arr[(n+n%2)/2] = 4;
    arr[(n+n%2)/2 + 1] = temp;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}