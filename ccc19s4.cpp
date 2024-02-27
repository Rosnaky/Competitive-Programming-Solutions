#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);


    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (int &i : arr) cin >> i;

    vector<vector<int>> dp(n, vector<int>(k));

    
}