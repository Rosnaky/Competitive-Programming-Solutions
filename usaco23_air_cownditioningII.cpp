#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> combAir;

void backtrack(vector<int>& curr, int n, int j) {
    if (curr.size() > n) return;
    
    combAir.push_back(curr);
    for (int i = j; i < n; i++) {
        curr.push_back(i);
        backtrack(curr, n, i+1);
        curr.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int nCows, nAir;
    cin >> nCows >> nAir;

    vector<vector<int>> cows;
    vector<vector<int>> conditioners;
    vector<int> temperature(101, 0);

    for (int i = 0; i < nCows; i++) {
        vector<int> temp(3);
        cin >> temp[0] >> temp[1] >> temp[2];
        for (int j = temp[0]; j <= temp[1]; j++) {
            temperature[j] = max(temperature[j], temp[2]);
        }
        cows.push_back(temp);
    }

    for (int i = 0; i < nAir; i++) {
        vector<int> temp(4);
        cin >> temp[0] >> temp[1] >> temp[2] >> temp[3];
        conditioners.push_back(temp);
    }

    vector<int> temp = {};
    backtrack(temp, conditioners.size(), 0);

    int ansCost = 1e9;
    for (vector<int>& curr : combAir) {
        int cost = 0;
        vector<int> temp = temperature;
        for (int cond : curr) {
            int a = conditioners[cond][0];
            int b = conditioners[cond][1];
            int reduce = conditioners[cond][2];
            int money = conditioners[cond][3];
            cost += money;

            for (int i = a; i <= b; i++) {
                temp[i] -= reduce;
            }
        }

        bool ok = true;
        for (int t : temp) {
            if (t > 0) {
                ok = false;
                break;
            }
        }

        if (ok) ansCost = min(ansCost, cost);
    }

    cout << ansCost;
}