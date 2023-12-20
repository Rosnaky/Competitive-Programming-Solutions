#include <vector>
#include <iostream>
#include <set>

using namespace std;


int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> graph = vector<vector<int>>(2, vector<int>(n, 0));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                ans += 3;
                if (j != n-1 && graph[i][j+1] == 1) {
                    ans -= 2;
                }
                if (i != 1 && graph[i+1][j] == 1 && j%2 == 0) {
                    ans -= 2;
                }
            }
        }
    }
    

    cout << ans;
}