#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

struct Edge
{
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

struct EdgeComparator {
    bool operator()(const Edge& edge1, const Edge& edge2) const {
        return edge1.w < edge2.w;
    }
};


vector<int> par, rnk;
vector<vector<vector<pair<int, int>>>> dual;
vector<Edge> edges1, edges2;

void makeSet(int n) {
    par[n] = n;
    rnk[n] = 1;
}

int Find(int n) {
    if (par[n] == n) {
        return n;
    }
    
    return par[n] = Find(par[n]);
}

bool Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a != b) {
        if (rnk[a] > rnk[b]) {
            par[b] = a;
        }
        else {
            if (rnk[a] == rnk[b]) {
                rnk[b]++;
            }
            par[a] = b;
        }

        return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int pens;
    cin >> pens;

    par = vector<int>(1005);
    rnk = vector<int>(1005);
    dual = vector<vector<vector<pair<int, int>>>>(1005, vector<vector<pair<int, int>>>(1005));
    edges1 = vector<Edge>();
    edges2 = vector<Edge>();

    // for (int i = 0; i < 1005; i++) {
    //     for (int j = 0; j < 1005; j++) {
    //         dual[i][j] = make_pair(-1, -1);
    //     }
    // }

    for (int i = 1; i <= pens; i++) {
        makeSet(i);
    }

    for (int i = 1; i <= pens; i++) {
        int e;
        cin >> e;

        vector<int> corners(e);
        vector<int> costs(e);

        for (int j = 0; j < e; j++) {
            cin >> corners[j];
        }
        for (int j = 0; j < e; j++) {
            cin >> costs[j];
        }

        for (int j = 0; j < e-1; j++) {
            int corner1 = corners[j];
            int corner2 = corners[j+1];
            int cost = costs[j];

            dual[corner1][corner2].push_back(pair(i, cost));
            dual[corner2][corner1].push_back(pair(i, cost));

            if (dual[corner1][corner2].size() == 2) {
                pair<int, int> pen1 = dual[corner1][corner2][0];
                pair<int, int> pen2 = dual[corner1][corner2][1];

                edges1.push_back(Edge(pen1.first, pen2.first, cost));
                edges2.push_back(Edge(pen1.first, pen2.first, cost));
            }
        }

        int corner1 = corners[e-1];
        int corner2 = corners[0];
        int cost = costs[e-1];
        dual[corner1][corner2].push_back(pair(i, cost));
        dual[corner2][corner1].push_back(pair(i, cost));
        if (dual[corner1][corner2].size() == 2) {
            pair<int, int> pen1 = dual[corner1][corner2][0];
            pair<int, int> pen2 = dual[corner1][corner2][1];

            edges1.push_back(Edge(pen1.first, pen2.first, cost));
            edges2.push_back(Edge(pen1.first, pen2.first, cost));
        }
    }
    sort(edges1.begin(), edges1.end(), EdgeComparator());
    int ansNotOutside = 0;
    int isOutside = 0;
    
    for (Edge e : edges1) {
        int u = e.u, v = e.v, w = e.w;
        if (Union(u, v)) {
            ansNotOutside += w;
        }
    }

    for (int i = 0; i < 1005; i++) {
        for (int j = 0; j < 1005; j++) {
            if (dual[i][j].size() == 1) {
                pair<int, int> pen = dual[i][j][0];
                edges2.push_back(Edge(pen.first, 0, pen.second));
            }
        }
    }
    for (int i = 1; i <= pens; i++) {
        makeSet(i);
    }
    sort(edges2.begin(), edges2.end(), EdgeComparator());
    for (Edge e : edges2) {
        int u = e.u, v = e.v, w = e.w;
        if (Union(u, v)) {
            isOutside += w;
        }
    }

    cout << min(ansNotOutside, isOutside) << endl;
}