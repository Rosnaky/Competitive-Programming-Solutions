#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool isAlive(vector<bool>& alive) {
    bool good = false;
    for (int i = 0; i < alive.size() && !good; i++) {
        good |= alive[i];
    }

    return good;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<vector<int>> start(n);
    for (int i = 0; i < n; i++) {
        char a; int b, c; cin >> a >> b >> c;

        start[i] = {a == 'N' ? 0 : a == 'E' ? 1 : a == 'S' ? 2 : 3, b, c};
    }

    vector<vector<int>> curr = start;
    vector<bool> alive(n, 1);
    vector<int> eats(n, 1);
    
    while (isAlive(alive)) {

        for (int i = 0; i < n; i++) {
            vector<int> pos = curr[i];
            if (pos[1] > 1e9 || pos[2] > 1e9) {
                eats[i] = -1;
                alive[i] = 0;
                continue;
            }
            pos[1] += pos[0] == 0;
            pos[1] -= pos[0] == 2;
            pos[2] += pos[0] == 1;
            pos[2] -= pos[0] == 3;

            bool good = true;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
            }

        }

    }

}