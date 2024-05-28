#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);

    int n, m, d, s; cin >> n >> m >> d >> s;

    vector<vector<int>> drank(n+1, vector<int>(m+1, 101));

    for (int i = 0; i < d; i++) {
        int a, b, c; cin >> a >> b >> c;

        drank[a][b] = min(drank[a][b], c);
    } 

    vector<int> sick(n+1, 101);
    for (int i = 0; i < s; i++) {
        int a, b; cin >> a >> b;
        
        sick[a] = b;
    }
    
    
    int ans = 0;

    for (int i = 1; i <= m; i++) {
        bool good = true;
        for (int j = 0; j <= n && good; j++) {
            if (drank[j][i] >= sick[j] && sick[j] < 101) good = false;
        }
        
        if (good) {
            int num = 0;
            for (int j = 1; j <= n; j++) {
                if (drank[j][i] < 101) num++;
            }
            ans = max(num, ans);
        }
    }

    cout << ans << "\n";
}