#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int m, n, k; cin >> n >> m >> k;

    vector<vector<char>> original(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            original[i][j] = s[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            for (int a = 0; a < m; a++) {
                for (int b = 0; b < k; b++) {
                    cout << original[i][a];
                }
            }
            cout << "\n";
        }
    }
}