#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> par;
vector<int> rnk;

int Find(int n) {
    if (par[n] == n) return n;
    return par[n] = Find(par[n]);
}

bool Union(int a, int b) {
    a = Find(a), b = Find(b);

    if (a == b) return 0;

    par[b] = a;
    rnk[a] += rnk[b];
    return 1;
} 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, a, b; cin >> n >> a >> b;

    vector<int> nums(n);
    for (int & i : nums) cin >> i;

    unordered_map<int, int> idx;

    for (int i = 0; i < n; i++) {
        idx[nums[i]] = i;
    }

    par = vector<int>(n+2);
    rnk = vector<int>(n+2, 1);
    
    for (int i = 0; i < n+2; i++) {
        par[i] = i;
    }

    for (int i = 0; i < n; i++) {
        if (!idx.count(a-nums[i]) && !idx.count(b-nums[i])) {
            cout << "NO\n";
            return 0;
        }

        if (idx.count(a-nums[i])) {
            Union(i, idx[a-nums[i]]);
        }
        if (idx.count(b-nums[i])) {
            Union(i, idx[b-nums[i]]);
        }
        if (!idx.count(a-nums[i])) {
            Union(i, n+1);
        }
        if (!idx.count(b-nums[i])) {
            Union(i, n);
        }
    }
    
    if (Find(n) == Find(n+1)) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << (Find(i) == Find(n+1)) << " ";
    }


    // while (1) {
    //     bool good = 0;
    //     for (int i = 0; i < n; i++) {
    //         if (idx.count(a-nums[i]) && idx.count(b-nums[i])) {
    //             continue;
    //         }
    //         if (idx.count(a-nums[i])) {
    //             good = 1;
    //             Union(idx[a-nums[i]], i);
    //             if (aidx == -1) {
    //                 aidx = Find(i);
    //             }
    //             else {
    //                 Union(i, aidx);
    //             }

    //             idx.erase(nums[i]);
    //             if (a-nums[i] != i) {
    //                 idx.erase(a-nums[i]);
    //             }
    //         }
    //         if (idx.count(b-nums[i])) {
    //             good = 1;
    //             Union(idx[b-nums[i]], i);
    //             if (bidx == -1) {
    //                 bidx = Find(i);
    //             }
    //             else {
    //                 Union(i, bidx);
    //             }

    //             idx.erase(nums[i]);
    //             if (b-nums[i] != i) {
    //                 idx.erase(b-nums[i]);
    //             }
    //         }
    //     }

    //     if (!good) {
    //         if (aidx != -1 && bidx != -1 && rnk[Find(aidx)] + rnk[Find(bidx)] == n) {
    //             cout << "YES\n";
    //             for (int i = 0; i < n; i++) {
    //                 if (Find(i) == Find(aidx)) cout << 0 << " ";
    //                 else cout << 1 << " ";
    //             }
    //         }
    //         else {
    //             cout << "NO\n";
    //         }
    //         return 0;
    //     }
    // }


}