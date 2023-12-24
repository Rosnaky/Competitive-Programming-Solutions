#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main() {
    int n;
    cin >> n;

    int ans = 0;

    string cows;
    cin >> cows;

    for (int i = n-1; i >= 1; i-=2) {
        if (cows[i] == cows[i-1]) continue;
        if (cows[i] == 'G' && ans%2 == 1) ans++;
        if (cows[i] == 'H' && ans%2 == 0) ans++;
    }

    cout << ans;

}