#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n;
    cin >> n;

    vector<int> ppl(n);
    for (int i = 1; i <= n; i++) {
        ppl[i-1] = i;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int interval;
        cin >> interval;
        vector<int> temp = {ppl[0]};

        for (int i = 1; i < int(ppl.size()); i++) {
            if ((i+1)%interval != 0) {
                temp.push_back(ppl[i]);
            }
        }
        ppl = temp;
        
    }
    for (int i : ppl) {
        cout << i << endl;
    }

}