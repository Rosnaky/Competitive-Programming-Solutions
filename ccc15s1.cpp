
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>


using namespace std;

vector<int> nums;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int prefix = 0;

    for (int i = 0; i < n; i++) {
        int curr;
        cin >> curr;

        if (curr == 0) {
            prefix -= nums[nums.size()-1];
            nums.pop_back();
        }
        else {
            prefix += curr;
            nums.push_back(curr);
        }
    }

    cout << prefix;

}