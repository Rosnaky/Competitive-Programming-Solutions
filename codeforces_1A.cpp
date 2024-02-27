#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, m, a; cin >> n >> m >> a;

    cout << (long long)(ceil((double)n/a)*ceil((double)m/a));
}