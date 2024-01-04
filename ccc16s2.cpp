#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

void getMax() {
    int n; cin >> n;

    priority_queue<int> dmoj, peg;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        dmoj.push(temp);
    }
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        peg.push(temp);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dmoj.top() > peg.top()) {
            ans += dmoj.top(); dmoj.pop();
        }
        else {
            ans += peg.top(); peg.pop();
        }
    }

    cout << ans;

}

void getMin() {
    int n; cin >> n;

    priority_queue<int> dmoj, peg;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        dmoj.push(temp);
    }
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        peg.push(temp);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += max(dmoj.top(), peg.top());
        dmoj.pop(); peg.pop();
    }

    cout << ans;
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t; t--;

    if (t) {
        getMax();
    }
    else {
        getMin();
    }
}