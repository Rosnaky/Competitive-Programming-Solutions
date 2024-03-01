#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int d; cin >> d;

    int y;

    while (cin >> y) {
        if (d > y) d+=y;
        else break;
    }

    cout << d;
}