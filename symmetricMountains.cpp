#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {

    vector<int> mountains;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        mountains.push_back(temp);
    }

    vector<int> ans(n, 0);

    for (int size = 1; size < n; size++) {
        int total = INT_MAX;
        for (int i = 0; i < n - size; i++) {
            int left = i;
            int right = left + size;
            int curr = 0;
            while (left < right) {
                curr += abs(mountains[left] - mountains[right]);
                left++;
                right--;
            }
            total = min(total, curr);
        }
        ans[size] = total;
    }

    for (int s : ans) {
        cout << s << " ";
    }
}