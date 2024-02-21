#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;



int n;

void check(vector<int> a, vector<int>& b, vector<pair<char, pair<int, int>>>& ans) {
    bool good = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            good = false;
            break;
        }
    }

    if (good) {
        cout << "YES\n";
        cout << ans.size() << "\n";
        for (auto p : ans) {
            cout << p.first << " " << p.second.first << " " << p.second.second << "\n";
        }
        exit(0);
    }
}


void solve(vector<int> a, vector<int>& b, vector<pair<char, pair<int, int>>>& ans) {
    check(a, b, ans);
    
    
    for (int i = 0; i < n; i++) {
        if (b[i] != a[i]) {
            // Swipe right
            
            for (int j = i; j >= 0; j--) {
                if (a[j] == b[i]) {
                    ans.push_back({'R', {j, i}});
                    vector<int> temp = a;
                    for (int k = j; k <= i; k++) {
                        temp[k] = a[j];
                    }
                    solve(temp, b, ans);
                    ans.pop_back();
                }
            }

            // Swipe left
            for (int j = i; j < n; j++) {
                if (a[j] == b[i]) {
                    ans.push_back({'L', {i, j}});
                    vector<int> temp = a;
                    for (int k = j; k >= i; k--) {
                        temp[k] = a[j];
                    }
                    solve(temp, b, ans);
                    ans.pop_back();
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    vector<int> a(n), b(n);

    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    vector<pair<char, pair<int, int>>> ans;
    solve(a, b, ans);

    cout << "NO";

}