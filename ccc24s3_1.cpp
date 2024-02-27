#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main() {

    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<int> a(n), b(n);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    vector<pair<char, pair<int, int>>> ans;
    /*
5
1 3 3 3 3
1 3 1 1 3
    */
    // check(a, b, ans);
    int i;
    for (i = 0; i < n; i++) {
        
        if (a[i] != b[i]) {
            int good = false;

            for (int j = i; j >= 0; j--) {
                if (a[j] == b[i]) {

                    if (ans.size() && ans[ans.size()-1].first == 'L' && ans[ans.size()-1].second.first <= i && ans[ans.size()-1].second.second >= i) {
                        cout << "NO";
                        return 0;
                    }

                    for (int k = j; k <= i; k++) a[k] = a[j];

                    ans.push_back({'R', {j, i}});
                    good = true;
                    i = j-1;
                    
                    break;
                }
            }
            if (good) continue;


            for (int j = i; j < n; j++) {
                if (a[j] == b[i]) {

                    // if (ans.size() && ans[ans.size()-1].first == 'R' && ans[ans.size()-1].second.first <= i && ans[ans.size()-1].second.second >= i) {
                    //     cout << "NO";
                    //     return 0;
                    // }

                    for (int k = i; k <= j; k++) a[k] = a[j];
                    
                    ans.push_back({'L', {i, j}});
                    good = true;
                    
                    break;
                }
            }
            

            if (!good) {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES\n";
    cout << ans.size() << "\n";
    for (auto p : ans) {
        cout << p.first << " " << p.second.first << " " << p.second.second << "\n";
    }
}