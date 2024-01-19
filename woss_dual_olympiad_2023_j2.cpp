#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> nums;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    nums = {a, b, c};

    int ans = 0;
    ans = max(ans, a*b*c);
    ans = max(ans, a*b+c);
    ans = max(ans, a+b*c);
    ans = max(ans, a*(b+c));
    ans = max(ans, (a+b)*c);
    ans = max(ans, a*c+b);
    ans = max(ans, a+c*b);
    ans = max(ans, (a+c)*b);
    ans = max(ans, a+b+c);
    

    cout << ans;
}