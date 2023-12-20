#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int curr;
    cin >> curr;
    int move = curr;
    curr++;

    cout << "You are now on square " << curr << endl;
    

    while (move != 0) {
        cin >> move;
        curr += move;
        if (move !=0) {
        if (curr == 54) curr = 19;
        if (curr == 90) curr = 48;
        if (curr == 99) curr = 77;

        if (curr == 9) curr = 34;
        if (curr == 40) curr = 64;
        if (curr == 67) curr = 86;

        if (curr > 100) curr -= move;

        cout << "You are now on square " << curr << endl;
        if (curr == 100) {
            cout << "You Win!";
            break;
        }
        }
    }

    if (curr != 100) {
        cout << "You Quit!";
    }

}