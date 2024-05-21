#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    int n, b; cin >> n >> b;

    vector<pair<int, int>> cows(n);
    vector<int> x(n), y(n);

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        cows[i] = {a, b};
        x[i] = a;
        y[i] = b;
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int ans = 1e9;

    for (int i = 0; i < n-1; i++) {

        if (x[i+1] - x[i] > 1) {
            
            for (int j = 0; j < n-1; j++) {

                if (y[j+1] - y[j] > 1) {

                    int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
                    int a = x[i] + 1, b = y[j] + 1; 
                    
                    for (auto cow : cows) {
                        if (cow.first > a && cow.second > b) q1++;
                        else if (cow.first > a && cow.second < b) q4++;
                        else if (cow.first < a && cow.second > b) q2++;
                        else q3++;
                    }

                    ans = min(ans, max(q1, max(q2, max(q3, q4))));

                }

            }

        }
    }

    cout << ans;
}