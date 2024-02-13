#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int g, p; cin >> g >> p;
    // vector<bool> arr(g);
    set<int> arr;
    for (int i = 1; i <= g; i++) {
        arr.insert(i);
    }

    for (int i = 0; i < p; i++) {
        int temp; cin >> temp;
        auto a = arr.lower_bound(temp);

        if (a == arr.end()) {
            continue;
        }

        if (*a > temp && a != arr.begin()) a--;
        else if (*a > temp) {
            cout << i;
            return 0;
        }
        

        arr.erase(a);
    }

    cout << p;
}   