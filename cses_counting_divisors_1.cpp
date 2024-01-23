#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

const int N = 1e6;
int max_div[N+1];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    for (int i = 2; i <= N; i++) {
        if (max_div[i] == 0) {
            for (int j = i; j <= N; j+=i) max_div[j] = i;
        }
    }

    int n; cin >> n; 

    while (n--) {
        int x; cin >> x;

        int div_num = 1;
        while (x!=1) {
            int prime = max_div[x];
            int count = 0;
            while (x%prime == 0) {
                count++;
                x/=prime;
            }
            div_num *= count+1;
        }
        cout << div_num << "\n";
    }
}