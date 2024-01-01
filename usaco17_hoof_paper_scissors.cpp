#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int n; cin >> n;

    vector<ll> hoof(n+1);
    vector<ll> paper(n+1);
    vector<ll> scissors(n+1);

    for (int i = 1; i <= n; i++) {
        char curr; cin >> curr;
        if (curr == 'P') paper[i] = paper[i-1]+1, hoof[i] = hoof[i-1], scissors[i] = scissors[i-1];
        else if (curr == 'H') paper[i] = paper[i-1], hoof[i] = hoof[i-1]+1, scissors[i] = scissors[i-1];
        else if (curr == 'S') paper[i] = paper[i-1], hoof[i] = hoof[i-1], scissors[i] = scissors[i-1]+1;
    }

    int ans = 0;

    
    
    for (int i = 1; i <= n; i++) {
        int maximum = max(paper[i], max(hoof[i], scissors[i]));
        int largeMax = max((paper[n]-paper[i]), max((hoof[n]-hoof[i]), (scissors[n]-scissors[i])));

        ans = max(ans, largeMax+maximum);
    }

    

    cout << ans;
}