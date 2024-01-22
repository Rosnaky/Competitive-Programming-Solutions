#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
 
using namespace std;
 
pair<int, int> dfs(int node, int par, vector<bool>& seen, vector<vector<int>>& adj) {
    if (seen[node]) return {-1, -1};
    seen[node] = true;
 
    int ans = node, temp = 0;
    for (int a : adj[node]) {
        if (a == par) continue;
        auto [farNode, dist] = dfs(a, node, seen, adj);
        if (dist > temp) {
            temp = dist;
            ans = farNode;
        }
    }
 
    return {ans, temp+1};
}
 
// int findMiddle(int node, int par, vector<bool>& seen, vector<vector<int>>& adj, int diameter, int& ans, int& target) {
//     if (seen[node]) return -1;
//     seen[node] = true;
 
//     if (node == target) return 1;
 
//     for (int a : adj[node]) {
//         int temp = findMiddle(a, node, seen, adj, diameter, ans, target);
//         if (temp == diameter/2) ans = node;
//         if (temp != -1) return temp+1;
//     }
 
//     return -1;
// }
 
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    int n; cin >> n;
    vector<vector<int>> tree1(n+1);
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        tree1[a].push_back(b);
        tree1[b].push_back(a);
    }
 
    int m; cin >> m;
    vector<vector<int>> tree2(m+1);
    for (int i = 0; i < m-1; i++) {
        int a, b; cin >> a >> b;
        tree2[a].push_back(b);
        tree2[b].push_back(a);
    }
 
    vector<bool> seen(n+1);
    vector<bool> seen1(n+1);
    int target1 = dfs(1, -1, seen, tree1).first;
    auto [node1, diameter1] = dfs(target1, -1, seen1, tree1);
 
    seen = vector<bool>(m+1);
    seen1 = vector<bool>(m+1);
    int target2 = dfs(1, -1, seen, tree2).first;
    auto [node2, diameter2] = dfs(target2, -1, seen1, tree2);
    // cout << diameter1 << " " << diameter2;
 
    // vector<bool> seen(n+1);
    // int middle1;
    // findMiddle(node1, -1, seen, tree1, diameter1, middle1, target1);
 
    // vector<bool> seen(m+1);
    // int middle2;
    // findMiddle(node2, -1, seen, tree2, diameter2, middle2, target2);
 
    cout << diameter1/2 + diameter2/2 + 1;
}






// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <cmath>

// using namespace std;

// pair<int, int> dfs(int node, int par, vector<bool>& seen, vector<vector<int>>& adj) {
//     if (seen[node]) return {-1, -1};
//     seen[node] = true;

//     int ans = node, temp = 0;
//     for (int a : adj[node]) {
//         if (a == par) continue;
//         auto [farNode, dist] = dfs(a, node, seen, adj);
//         if (dist > temp) {
//             temp = dist;
//             ans = farNode;
//         }
//     }

//     return {ans, temp+1};
// }

// int findMiddle(int node, int par, vector<bool>& seen, vector<vector<int>>& adj, int diameter, int& ans, int& target) {
//     if (seen[node]) return -1;
//     seen[node] = true;

//     if (node == target) return 1;

//     for (int a : adj[node]) {
//         int temp = findMiddle(a, node, seen, adj, diameter, ans, target);
//         if (temp == diameter/2) ans = node;
//         if (temp != -1) return temp+1;
//     }

//     return -1;
// }


// int main() {
//     ios_base::sync_with_stdio(0); cin.tie(0);

//     int n; cin >> n;
//     vector<vector<int>> tree1(n+1);
//     for (int i = 0; i < n-1; i++) {
//         int a, b; cin >> a >> b;
//         tree1[a].push_back(b);
//         tree1[b].push_back(a);
//     }

//     int m; cin >> m;
//     vector<vector<int>> tree2(m+1);
//     for (int i = 0; i < m-1; i++) {
//         int a, b; cin >> a >> b;
//         tree2[a].push_back(b);
//         tree2[b].push_back(a);
//     }

//     vector<bool> seen(n+1);
//     vector<bool> seen1(n+1);
//     int target1 = dfs(1, -1, seen, tree1).first;
//     auto [node1, diameter1] = dfs(target1, -1, seen1, tree1);

//     seen = vector<bool>(m+1);
//     seen1 = vector<bool>(m+1);
//     int target2 = dfs(1, -1, seen, tree2).first;
//     auto [node2, diameter2] = dfs(target2, -1, seen1, tree2);
//     // cout << diameter1 << " " << diameter2;

//     seen = vector<bool>(n+1);
//     int middle1;
//     findMiddle(node1, -1, seen, tree1, diameter1, middle1, target1);

//     seen = vector<bool>(m+1);
//     int middle2;
//     findMiddle(node2, -1, seen, tree2, diameter2, middle2, target2);

//     seen = vector<bool>(n+1);
//     seen1 = vector<bool>(m+1);
//     cout << dfs(middle1, -1, seen, tree1).second + dfs(middle2, -1, seen1, tree2).second-1;

// }