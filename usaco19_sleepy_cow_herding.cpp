#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int minCow(vector<int> cows) {
    int end1 = cows[0];
    int end2 = cows[2];
    int mid = cows[1];

    if (mid + 2 == end2) return 1;
    else if (mid-2 == end1) return 1;
    return 2;
}

int maxCow(vector<int> cows) {
    int end1 = cows[0];
    int end2 = cows[2];
    int mid = cows[1];
    // cout << end1 << " " << mid << " " << end2 << endl;

    if (mid-end1 == 1 && end2-mid == 1) return 0;


    if (mid - end1 > end2 - mid) {
        return 1 + maxCow({end1, (mid+end1)/2, mid});
    }
    else {
        return 1 + maxCow({mid, (end2+mid)/2, end2});
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    int a, b, c;
    cin >> a >> b >> c;
    int l = b - a - 1;
    int r = c - b - 1;
    if (l == 0 && r == 0)
    cout << 0 << endl;
    else if (l == 1 || r == 1)
    cout << 1 << endl;
    else
    cout << 2 << endl;
    cout << max(l, r);
}