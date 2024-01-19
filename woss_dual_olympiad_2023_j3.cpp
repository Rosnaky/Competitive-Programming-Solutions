#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> nums;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;

    vector<int> prefix(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> prefix[i];
        prefix[i]+=prefix[i-1];
    }

    for (int i = 0; i < q; i++) {
        int a, b, c; cin >> a >> b >> c;
        if (a == 1) {
            prefix[b-1] += c;
        }
        else if (a == 2) {
            prefix[b] -= c;
        }
        else {
            cout << prefix[c] - prefix[b-1] <<"\n";
        }
    }

}