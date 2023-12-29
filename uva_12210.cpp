#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int tc = 1;

void solve(int n, int m) {
    multiset<int> bach;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        bach.insert(temp);
    }
    multiset<int> spin;
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        spin.insert(temp);
    }

    while (bach.size() != 0 && spin.size() != 0) {
        auto b = bach.rbegin();
        auto s = spin.lower_bound(*b);
        // cout << *b << " " << *s << endl;
        spin.erase(s);
        bach.erase(next(b).base());
    }

    cout << "Case " << tc << ": " << bach.size();
    if (bach.size() == 0) cout << "\n";
    else cout << " " << *bach.begin();
    tc++;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    while (n != 0 && m != 0) {
        solve(n, m);
        cin >> n >> m;
    }
}