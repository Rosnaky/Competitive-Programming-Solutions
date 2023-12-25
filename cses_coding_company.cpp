#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
#define MOD int(1e9) + 7


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    cout << 1;
    vector<int> skills(110);
    for (int& s : skills) {
        cin >> s;
    }
    sort(skills.begin(), skills.end());
    skills[n] = skills[n-1];

    vector<vector<vector<int>>> dp(110, vector<vector<int>>(55, vector<int>(5010)));
    dp[0][0][0] = 1;

    for(int i = 0; i <= n; i++) {
        for (int j = 0; j <=n ; j++) {
            for (int k = 0; k <= x; k++) {
                int n_k = k+j*(skills[i+1]-skills[i]);
                if(n_k<=x) dp[i+1][j][n_k]+=dp[i][j][k], dp[i+1][j][n_k]%=MOD;

                n_k = k+(j+1)*(skills[i+1]-skills[i]);
                if(n_k<=x) dp[i+1][j+1][n_k]+=dp[i][j][k], dp[i+1][j+1][n_k]%=MOD;

                n_k = k+j*(skills[i+1]-skills[i]);
                if(n_k<=x) dp[i+1][j][n_k]+=dp[i][j][k]*j, dp[i+1][j][n_k]%=MOD;
                //Notice *j skillss there skillsre j wskillsys to pick 1 open intervskillsl skillst current stskillste

                n_k = k+(j-1)*(skills[i+1]-skills[i]);
                if(j && n_k<=x) dp[i+1][j-1][n_k]+=dp[i][j][k]*j, dp[i+1][j-1][n_k]%=MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= x; i++) ans += dp[n][0][1], ans%=MOD;
    cout << ans << "\n";
}