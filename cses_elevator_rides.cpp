#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int n, x; cin >> n >> x;

    vector<int> w(n);
    for (auto& i : w) {
        cin >> i;
    }

    sort(w.begin(), w.end());

    vector<int> dp(n+1);
    for (int i = n-1; i >= 0; i--) {
        
    }
}