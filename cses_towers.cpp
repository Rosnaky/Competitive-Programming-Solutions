#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> cubes(n);

    for (int i = 0; i < n; i++) {
        cin >> cubes[i];
    }

    multiset<int> towers = {cubes[0]};

    for (int i = 1; i < n; i++) {
        int cube = cubes[i];
        auto it = towers.upper_bound(cube);

        if (it == towers.end()) {
            towers.insert(cube);
            continue;
        }

        towers.erase(it);
        towers.insert(cube);
    }

    cout << towers.size();
}