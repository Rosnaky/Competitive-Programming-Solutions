#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<string> s(1);
    cin >> s[0];
    vector<int> par = {0};

    int n; cin >> n; bool sorted = true;

    for (int i = 0; i < n; i++) {
        char tok; cin >> tok;
        if (tok == 'C') {
            int index; char c; cin >> index >> c;
            string temp = s[index-1] + c;
            auto it = find(s.begin(), s.end(), temp);
            
            if (it == s.end()) par.push_back(index-1);
            else par.push_back(it-s.begin());
            s.push_back(temp);
        }
        else {
            string t; cin >> t;

            int ans = 0; int index = -1;
            for (int k = s.size()-1; k >= 0; k--) {
                string a = s[k];
                int temp = 0;
                for (int j = 0; j < min(t.size(), a.size()); j++) {
                    if (t[j] == a[j]) temp++;
                    else break;
                }

                if (temp > ans) {
                    int curr = k;
                    while (curr != 0 && s[par[curr]].size() >= temp) {
                        curr = par[curr];
                    }
                    index = curr+1;
                    ans = temp;
                    break;
                }
            }
            cout << index << "\n";
        }
    }
}