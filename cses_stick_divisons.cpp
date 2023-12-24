#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, n;
    cin >> x >> n;

    priority_queue<int, vector<int>, greater<int>> sticks;

    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        sticks.push(l);
    }

    long long ans = 0;
    long long count = 0;
    long long temp = 0;
    while (!sticks.empty()) {
        if (count%2 == 0) {
            temp += sticks.top();
            sticks.pop();
        }
        else {
            temp += sticks.top();
            sticks.pop();
            sticks.push(temp);
            ans += temp;
            temp = 0;
        }
        count++;
    }


    cout << ans;
}