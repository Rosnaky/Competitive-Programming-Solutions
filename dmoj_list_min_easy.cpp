#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
#define mod ll(1e9+7)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n; int temp;
    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        q.push(-temp);
    }

    for (int i = 0; i < n; i++) {cout << 0-q.top() << "\n"; q.pop();}
}