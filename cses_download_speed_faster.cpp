#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;
typedef long long ll;

const int MAXN = 5000;
const ll INF = 1e15;

int n, m, source, sink;
ll capacity[MAXN+1][MAXN+1];
ll flow[MAXN+1][MAXN+1];
vector<ll> excess;
vector<ll> height;
vector<ll> next_son;
queue<int> excess_vertexes;

void push(int u, int v) {
    ll d = min(excess[u], capacity[u][v] - flow[u][v]);
    flow[u][v] += d;
    flow[v][u] -= d;

    excess[u] -= d;
    excess[v] += d;

    if (d && excess[v] == d) {
        excess_vertexes.push(v);
    }
}

void relabel(int u) {
    ll d = INF;
    for (int v = 1; v <= n; v++) {
        if (capacity[u][v] > flow[u][v]) {
            d = min(d, height[v]);
        }
    }
    if (d < INF) {
        height[u] = d+1;
    }
}

void discharge(int u) {
    while (excess[u] > 0) {
        if (next_son[u] <= n) {
            int v = next_son[u];
            if (capacity[u][v] > flow[u][v] && height[u] > height[v]) {
                push(u, v);
            } else {
                next_son[u]++;
            }
        } else {
            relabel(u);
            next_son[u] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    source = 1;
    sink = n;
    excess.resize(n+1);
    height.resize(n+1);
    next_son.resize(n+1);
    
    height[source] = n;
    excess[source] = INF;

    for (int i = 1; i <= m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        capacity[x][y] += c;
    }

    for (int i = 1; i <= n; i++) {
        if (i == source) continue;
        push(source, i);
    }

    while (!excess_vertexes.empty()) {
        int node = excess_vertexes.front();
        excess_vertexes.pop();
        if (node != source && node != sink) {
            discharge(node);
        }
    }

    ll max_flow = 0;
    for (int node = 1; node <= n; node++) {max_flow += flow[node][sink];}
    cout << max_flow;
}