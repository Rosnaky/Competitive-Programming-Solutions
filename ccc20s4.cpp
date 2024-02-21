#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);


    string s; cin >> s;
    int n = s.size();

    int a = 0;
    for (char x : s) a += (x == 'A');

    if (a == 0 || a == n) {
        cout << 0;
        return 0;
    }

    vector<int> pre(n+1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] + (s[i-1] == 'B');
    }

    if (a) a--;

    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        int temp = pre[(i+a)%(n+1)] - pre[i-1];
        if (temp < 0) {
            temp = pre[n] - pre[i-1] + pre[(i+a+1)%(n+1)];
        } 

        ans = min(ans, temp);
    }

    cout << ans;

}