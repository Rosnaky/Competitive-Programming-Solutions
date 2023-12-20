#include <vector>
#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> heights;

    for (int i = 0; i <= n; i++) {
        int temp;
        cin >> temp;
        heights.push_back(temp);
    }

    double ans = 0;

    for (int i = 0; i < n; i++) {
        int l = heights[i];
        int r = heights[i + 1];
        int w;
        cin >> w;

        ans += (l + r) * w / 2.0;
    }
    cout << ans;
}