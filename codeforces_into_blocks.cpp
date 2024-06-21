#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, _; cin >> n >> _;

    vector<int> a(n);

    for (int &i : a) cin >> i;

    unordered_map<int, int> freq, firstlast;
    
    for (int i = 0; i < n; i++) {
        firstlast[a[i]] = i;
        freq[a[i]]++;
    }

    int cnt = 0, total = 0, maxi = -1, tempMaxi = 0;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, firstlast[a[i]]);
        cnt++;
        tempMaxi = max(tempMaxi, freq[a[i]]);
        if (i == maxi) {
            total += cnt - tempMaxi;
            tempMaxi = 0;
            cnt = 0;
        }
        
    }

    cout << total;

    
}