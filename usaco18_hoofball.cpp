#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <set>


using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);

    int n; cin >> n;

    vector<int> cows(n);
    
    for (int &i : cows) cin >> i;

    sort(cows.begin(), cows.end());

    vector<set<int>> reaches(n);
    
    for (int i = 0; i < n; i++) {
        reaches[i].insert(i);
        
        vector<bool> seen(n);
        int j = i;
        while (j >= 0 && j < n && !seen[j]) {
            seen[j] = 1;
            if (j > 0 && j+1 < n) j = cows[j]-cows[j-1] <= cows[j+1]-cows[j] ? j-1 : j+1;
            else if (j == 0 && j+1 < n) j = j+1;
            else if (j == n-1 && j-1 >= 0) j = j-1;

            reaches[i].insert(j);
        }
    }


    sort(reaches.begin(), reaches.end(), [](set<int>& a, set<int>& b) {
        return a.size() < b.size();
    });

    vector<bool> needed(n, 0);

    for (int a = 0; a < n; a++) {
        cout << cows[a] << ": ";
        for (auto i : reaches[a]) {
            cout << cows[i] << " ";
        }
        cout << "\n";
    }

}