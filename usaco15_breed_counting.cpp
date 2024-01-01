#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int n, q; cin >> n >> q;

    vector<int> ones(n+1);
    vector<int> twos(n+1);
    vector<int> threes(n+1);

    int temp; cin >> temp;
    if (temp == 1) ones[1] = 1;
    else if (temp == 2) twos[1] = 1;
    else threes[1] = 1;

    for (int i = 2; i <= n; i++) {
        cin >> temp;
        if (temp == 1) ones[i] = 1+ones[i-1], twos[i] = twos[i-1], threes[i] = threes[i-1];
        else if (temp == 2) twos[i] = 1+twos[i-1], ones[i] = ones[i-1], threes[i] = threes[i-1];
        else threes[i] = 1+threes[i-1], ones[i] = ones[i-1], twos[i] = twos[i-1];
    }

    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;l--;
        cout << ones[r]-ones[l] << " " << twos[r]-twos[l] << " " << threes[r]-threes[l] << "\n";
    }
}