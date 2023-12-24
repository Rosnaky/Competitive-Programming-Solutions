#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int minutes, n;
    cin >> n >>minutes;

    vector<int> algorithms(n);
    for (int i = 0; i < n;i++) cin >> algorithms[i];

    sort(algorithms.begin(), algorithms.end());

    int i = 0;
    int curr =0;
    while (i < algorithms.size() && curr + algorithms[i] <= minutes) {
        curr += algorithms[i];
        i++;
    }

    cout << i;
}