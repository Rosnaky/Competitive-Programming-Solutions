#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }

    int even = 0;
    int odd = 0;
    for (int i = 0; i < n; i++) {
        if (cows[i]%2 == 0) even++;
        else odd++;
    }

    while (odd > even) {
        odd -= 2;
        even++;
    }
    if (even > odd+1) even = odd+1;
    cout << even+odd;
}