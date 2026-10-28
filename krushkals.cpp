#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

// Disjoint Set Union (Union-Find)
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]) parent[px] = py;
        else if (rank[px] > rank[py]) parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Kruskal {
public:
    int minimumSpanningTree(int V, vector<Edge>& edges) {
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.w < b.w;
        });

        DSU dsu(V);
        int mstCost = 0;
        vector<Edge> mstEdges;

        for (auto &e : edges) {
            if (dsu.find(e.u) != dsu.find(e.v)) {
                dsu.unite(e.u, e.v);
                mstCost += e.w;
                mstEdges.push_back(e);
            }
        }

        cout << "Edges in the Minimum Spanning Tree:\n";
        for (auto &e : mstEdges) {
            cout << e.u << " -- " << e.v << " == " << e.w << endl;
        }

        return mstCost;
    }
};

int main() {
    int V = 4; // number of vertices
    vector<Edge> edges;
    edges.push_back(Edge(0, 1, 10));
    edges.push_back(Edge(0, 2, 6));
    edges.push_back(Edge(0, 3, 5));
    edges.push_back(Edge(1, 3, 15));
    edges.push_back(Edge(2, 3, 4));

    Kruskal k;
    int cost = k.minimumSpanningTree(V, edges);

    cout << "Minimum Cost of Spanning Tree: " << cost << endl;

    cout << "This program is executed by Shivam Maurya (Roll No: 2400320101044)" << endl;
    return 0;
}
