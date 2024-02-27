#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<ll> prefixX(n+1);
    vector<ll> prefixY(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> prefixX[i] >> prefixY[i];
        prefixX[i] += prefixX[i-1];
        prefixY[i] += prefixY[i-1];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<= n; j++) {

        }
    }
}