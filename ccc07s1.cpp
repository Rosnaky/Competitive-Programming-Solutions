#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int year, month, day;
        cin >> year >> month >> day;

        if (2007 - year > 19) {
            cout << "Yes" << endl;
            continue;
        }
        if (2007 - year == 18 && month < 2) {
            cout << "Yes" << endl;
            continue;
        }
        if (2007 - year == 18 && month == 2 && day <= 27) {
            cout << "Yes" << endl;
            continue;
        }
        if (2007 - year - 1 == 18) {

        }
        cout << "No" << endl;
    }
}