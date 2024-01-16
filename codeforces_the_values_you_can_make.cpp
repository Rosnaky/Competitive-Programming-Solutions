#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int N = 505;

bool dp[2][N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    dp[0][0][0] = 1;

    for (int i = 1; i <= n; i++) {
        int curr = i%2;
    }
    
}