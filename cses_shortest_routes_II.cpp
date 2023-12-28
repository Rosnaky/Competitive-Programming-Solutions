#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

typedef long long ll;
#define BIG 10000000000000

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> graph(n+1, vector<ll>(n+1, BIG));

    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        graph[a][b] = min(graph[a][b], c);
        graph[b][a] = min(graph[b][a], c);
    }

    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                ll dist = graph[i][k] + graph[j][k];
                graph[i][j] = min(graph[i][j], dist);
                graph[j][i] = min(graph[j][i], dist);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        if (a == b) {
            graph[a][b] = 0;
        }
        else if (graph[a][b] == BIG) {
            graph[a][b] = -1;
        }

        cout << graph[a][b] << "\n";
    }
}