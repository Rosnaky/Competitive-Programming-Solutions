#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, k; cin >> n >> m >> k;

    int left = 0, right = 0, curr = 0;
    for (int i = 0; i < m; i++) {
        int a, b, t; cin >> a >> b >> t;
        int s = false;
        
        if (a != 0 && b != 0) {
            if (abs(left-a) < abs(left-b)) {
                if (abs(left-a) < k*(t-curr)) {
                    s = true;
                }
            }
            else if (abs(left-b) < k*(t-curr)) {
                s = true;
            }
        }
        else if (a != 0) {
            if (abs(left-a) < k*(t-curr)) {
                s = true;
            }
        }
        else {
            if (abs(left-b) < k*(t-curr)) {
                s = true;
            }
        }

        if (a != n && b != n) {
            if (abs(right-a) < abs(right-b)) {
                if (abs(right-a) < k*(t-curr)) {
                    s = true;
                }
            }
            else if (abs(right-b) < k*(t-curr)) {
                s = true;
            }
        }
        else if (a != 0) {
            if (abs(right-a) < k*(t-curr)) {
                s = true;
            }
        }
        else {
            if (abs(right-b) < k*(t-curr)) {
                s = true;
            }
        }

        if (!s) {
            cout << "NO";
            return 0;
        }

        left = a, right = b, curr = t;
        cout << left << " " << right << " " << t << "\n";
    }
    cout << "YES";
}