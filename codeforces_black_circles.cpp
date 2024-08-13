#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll getDistance(int xi, int yi, int xf, int yf) {
    return 1ll * (yf-yi)*(yf-yi) + 1ll * (xf-xi)*(xf-xi);
}

void solve() {

    int n; cin >> n;
    vector<vector<int>> circles(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> circles[i][0] >> circles[i][1];
    }

    int xi, yi, xf, yf; cin >> xi >> yi >> xf >> yf;

    ll distance = getDistance(xi, yi, xf, yf);


    bool good = 1;
    for (int i = 0; i < n; i++) {
        // cout << distance << " " << getDistance(xf, yf, circles[i][0], circles[i][1]) << endl; 
        if (distance >= getDistance(xf, yf, circles[i][0], circles[i][1])) {
            good = 0;
            break;
        }
    }

    if (!good) {
        cout << "no\n";
        return;
    }
    cout << "yes\n";


}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}