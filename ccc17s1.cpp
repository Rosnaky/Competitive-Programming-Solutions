#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> input(n);
    cin >> input[0];
    for (int i = 1; i < n; i++) {
        int temp;
        cin >> temp;
        input[i] = temp + input[i-1];
    }

    int score1 = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int curr;
        cin >> curr;
        score1 += curr;

        if (score1 == input[i]) {
            ans = i+1;
            break;
        }

    }
    cout << ans;
}