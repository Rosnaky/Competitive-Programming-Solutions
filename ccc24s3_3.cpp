#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


bool isSubsequence(vector<int>& a, vector<int>& b) {
    vector<int> bprime = {b[0]};

    for (int i = 1; i < b.size(); i++) {
        if (b[i] != b[i-1]) {
            bprime.push_back(b[i]);
        }
    }

    int j = 0;
    for (int i : a) {
        if (j < bprime.size() && bprime[j] == i) j++;
    }

    return j == bprime.size();
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;

    vector<int> a(n), b(n), bprime;

    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    if (!isSubsequence(a, b)) {
        cout << "NO";
        return 0;
    } 

    vector<pair<int, int>> swipes, left, right;

    int j = 0;
    for (int i = 0; i < a.size(); i++) {
        while (j < b.size() && a[i] == b[j]) {
            j++;
        }
        j--;
        if (i < j) {
            cout << i << " " << j << endl;
            swipes.push_back({i, j});
        }
        else if (i > j) {
            cout << i+1 << " " << j+1 << endl;
            swipes.push_back({i+1, j+1});
        }
        j++;
    }

    

    cout << "YES\n";
}