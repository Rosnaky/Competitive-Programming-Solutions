#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n, m, k;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;

    vector<int> s(n, 0);
    s[0] = 1;
    vector<int> length(n, 1);
    
    ll curr = 1;

    for (int i = 1; i < n; i++) {
        if (k - curr == n-i) {
            s[i] = s[i-1];
            curr++;
            continue;
        }
        
        int temp = i-length[i-1];
        // cout << temp << endl;
        while (length[i-1]-length[temp]+curr+2 > k && temp != i) {
            temp++;
        }
        
        int next = 1;
        while (next <= s[i-1] && next >= s[temp] && next != m+1) next++;
        length[i] = length[i-1]-length[temp]+2;
        curr += length[i];
        if (next == m+1) {
            length[i]--;
            next = 1;
        }
        s[i] = next;
    }
    // cout << curr << endl;

    if (curr != k){
        cout << -1; return 0;
    }

    for (int i : s) cout << i << " ";
    // cout << endl;
    // for (int i : length) cout << i << " ";
}