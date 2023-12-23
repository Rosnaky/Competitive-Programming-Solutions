#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const vector<string> cows = {"Beatrice", "Belinda", "Bella",     "Bessie",
                             "Betsy",    "Blue",    "Buttercup", "Sue"};

vector<vector<string>> orderings;

void build(vector<string> curr) {
    if (int(curr.size()) == 8) {
        orderings.push_back(curr);
        return;
    }

    for (const string& cow: cows) {
        if (find(curr.begin(), curr.end(), cow) == curr.end()) {
            curr.push_back(cow);
            build(curr);
            curr.pop_back();
        }
    }
}

int loc(const vector<string>& curr, const string& key) {
    return find(curr.begin(), curr.end(), key) - curr.begin();
}


int main() {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    int n;
    cin >> n;

    vector<pair<string, string>> restrictions;
    for (int i = 0; i < n; i++) {
        string cow1 = "";
        string cow2 = "";
        for (int j = 0; j < 6; j++) {
            string word;
            cin >> word;
            cow1 = cow1.empty() ? word : cow1;
            cow2 = word;
        }
        restrictions.emplace_back(cow1, cow2);
    }

    build({});

    for (vector<string>& curr : orderings) {
        bool ok = true;
        for (const pair<string, string>& rule : restrictions) {
            if (abs(loc(curr, rule.first) - loc(curr, rule.second)) > 1) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            for (const string& i : curr) {
                cout << i << "\n";
            }
            break;
        }
    }
}