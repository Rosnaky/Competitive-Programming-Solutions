#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

vector<ll> sum, cnt;
ll n, c; 

ll point(int a, int b) {
    if (a <= b) {
        return sum[b]-(a==0? 0:sum[a-1]);
    }
    else {
        return sum[b]+sum[c-1]-sum[a-1];
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> c;
    sum.resize(c);
    cnt.resize(c);

    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        cnt[t]++;
    }

    sum[0] = cnt[0];

    for (int i = 1; i < c; i++) sum[i] = sum[i-1]+cnt[i];
    ll ans = n*(n-1)*(n-2)/6;
    for (ll i = 0; i < c; i++) {
        ll opposite = (i+c/2)%c;
        ll tot = point(i+1, opposite);
        ans -= cnt[i]*tot*(tot-1)/2;
        ans-=cnt[i]*(cnt[i]-1)/2*tot;
        ans-=cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
    }
    if(c%2==0)
    {
        for(ll i=0;i<c/2;i++)
        {
            ll opposite=i+c/2; 
            ans+=cnt[i]*(cnt[i]-1)/2*cnt[opposite]; 
            ans+=cnt[i]*cnt[opposite]*(cnt[opposite]-1)/2; 
        }
    }
    cout<<ans<<endl; 


}