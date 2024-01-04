#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);


    int year; cin >> year; year++;

    while (true) {

        string temp = to_string(year);
        map<char, int> counts;
        bool valid = true;
        for (int i = 0; i < temp.size(); i++) {
            char c = temp[i];
            counts[c]++;
            if (counts[c] > 1) {
                valid = false;
                break;
            }
        }

        if (valid) {
            cout << year;
            return 0;
        }
        year++;
    }
}