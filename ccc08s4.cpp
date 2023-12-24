#include <vector>
#include <iostream>
#include <string>
#include <climits>


using namespace std;

int ans;
int hand[4];
vector<int> handPerm;
bool chosen[4];

int operation(int op, int num1, int num2) {
    switch (op) {
        case 0:
            return num1 + num2;
        case 1:
            return num1 - num2;
        case 2:
            return num1 * num2;
        case 3:
            if (num2 == 0 || num1%num2 != 0) return INT_MIN;
            return num1/num2;
    }
    return INT_MIN;
}


void backtrack() {
    if (handPerm.size() == 4) {
        for (int op1 = 0; op1 < 4; op1++) {
            for (int op2 = 0; op2 < 4; op2++) {
                for (int op3 = 0; op3 < 4; op3++) {
                    int first = operation(op1, handPerm[0], handPerm[1]);
                    if (first == INT_MIN) continue;
                    
                    int second = operation(op2, first, handPerm[2]);
                    if (second == INT_MIN) continue;

                    int third = operation(op3, second, handPerm[3]);
                    if (third == INT_MIN) continue;

                    if (third <= 24) ans = max(ans, third);
                }
            }
        }

        for (int op1 = 0; op1 < 4; op1++) {
            for (int op2 = 0; op2 < 4; op2++) {
                for (int op3 = 0; op3 < 4; op3++) {
                    int first = operation(op1, handPerm[0], handPerm[1]);
                    if (first == INT_MIN) continue;
                    
                    int second = operation(op2, handPerm[2], handPerm[3]);
                    if (second == INT_MIN) continue;

                    int third = operation(op3, first, second);
                    if (third == INT_MIN) continue;

                    if (third <= 24) ans = max(ans, third);
                }
            }
        }
    }


    else {
        for (int i = 0; i < 4; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            handPerm.push_back(hand[i]);
            backtrack();
            chosen[i] = false;
            handPerm.pop_back();
        }
    }
}


int main() {
    int numHands;
    cin >> numHands;

    for (int h = 0; h < numHands; h++) {
        ans = INT_MIN;
        for (int i = 0; i < 4; i++) cin >> hand[i];

        backtrack();
        cout << ans << "\n";
    }
}