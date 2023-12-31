#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 12;

    cout << (1 << (32 - __builtin_clz(n-1)));
}