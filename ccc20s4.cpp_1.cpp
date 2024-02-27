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
    int b = 0;
    for (char x : s) a += (x == 'A');
    for (char x : s) b += (x == 'B');

    if (a == 0 || a == n) {
        cout << 0;
        return 0;
    }

    vector<int> preB(n+1), preC(n+1);
    for (int i = 1; i <= n; i++) {
        preB[i] = preB[i-1] + (s[i-1] == 'B');
        preC[i] = preC[i-1] + (s[i-1] == 'C');
    }

    if (a) a--;
    if (b) b--;

    for (int a : preB) cout << a << " "; cout << endl;
    for (int a : preC) cout << a << " "; cout << endl;

    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        int temp = preB[(i+a)%(n+1)] - preB[i-1];
        if (temp < 0) {
            temp = preB[n] - preB[i-1] + preB[(i+a+1)%(n+1)];
        } 

        int temp1 = preC[(i+a)%(n+1)] - preC[i-1];
        if (temp1 < 0) {
            temp1 = preC[n] - preC[i-1] + preC[(i+a+1)%(n+1)];
        } 

        temp = b+a - min(temp, temp1);
        ans = min(ans, temp);

        cout << temp << " ";
    }

    cout << ans;

}