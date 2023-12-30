#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> n >> m;

    int k;
    cin >> k;

    int gold = 0;

    vector<bool> rows(n);
    vector<bool> cols(m);

    int r = 0, c = 0;

    for (int i = 0; i < k; i++) {
        char a;
        int index;
        cin >> a >> index;
        index--;

        if (a == 'R') {
            if (rows[index]) {
                rows[index] = false;
                r--;
            }
            else {
                rows[index] = true;
                r++;
            }
        }
        else {
            if (cols[index]) {
                cols[index] = false;
                c--;
            }
            else {
                cols[index] = true;
                c++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (rows[i]) {
            gold += m-c;
        }
    }
    for (int i = 0; i < m; i++) {
        if (cols[i]) {
            gold += n-r;
        }
    }

    cout << gold;
}