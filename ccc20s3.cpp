#include <vector>
#include <unordered_set>
#include <string>
#include <iostream>
using namespace std;

long long hsh[200010], pw[200010], base = 131;
int fs[26], ft[26];
unordered_set<long long> st;

bool check(){
    for (int i = 0; i < 26; i++){
        if (fs[i] != ft[i]) return false;
    }
    return true;
}

long long getSubHash(int l, int r){
    return hsh[r] - hsh[l-1]*pw[r-l+1];
}

int main() {

    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    for (int i = 1; i <= n; i++){
        fs[s[i-1]-'a']++;
    }
    pw[0] = 1;
    // Generate hash which can be calculated with sliding window
    // Kind of like prefix sum array
    for (int i = 1; i <= m; i++){
        hsh[i] = hsh[i-1]*base + t[i-1];
        pw[i] = pw[i-1]*base;
    }
    for (int i = 1; i <= m; i++){
        // Sliding window
        ft[t[i-1]-'a']++;
        if (i < n) continue;
        if (i > n) ft[t[i-n-1]-'a']--;
        // Rolling hash
        if (check()) st.insert(getSubHash(i-n+1, i));
    }
    cout << st.size() << endl;
}