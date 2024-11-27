#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int u) {
        if (u != parent[u]) parent[u] = find(parent[u]);
        return parent[u];
    }

    bool unite(int u, int v) {
        int rootU = find(u), rootV = find(v);
        if (rootU == rootV) return false;

        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
        return true;
    }
};

struct Edge {
    int u, v;
    ll cost;
    Edge(int u, int v, ll cost) : u(u), v(v), cost(cost) {}
};

bool comp(const Edge& e1, const Edge& e2) {
    return e1.cost < e2.cost;
}

ll minimumConnectionCost(int n, vector<ll>& pos, vector<ll>& cost) {
    vector<pli> points(n);
    for (int i = 0; i < n; i++) {
        points[i] = {pos[i], i};  // Store position and original index
    }
    vector<pair<int,int>> a;
    for(int i=0;i<n;i++){
        a.push_back({pos[i],cost[i]});
    }
    // Sort points by position
    sort(points.begin(), points.end());

    vector<Edge> edges;

    // Add edges only between consecutive points in sorted order
    for (int i = 1; i < n; i++) {
        int u = points[i - 1].second;
        int v = points[i].second;
        ll dist = abs(points[i].first - points[i - 1].first);
        ll edgeCost = min(cost[u], cost[v]) * dist;
        edges.emplace_back(u, v, edgeCost);
    }

    // Sort edges by cost
    sort(edges.begin(), edges.end(), comp);

    // Kruskal's algorithm to find the MST
    DisjointSet dsu(n);
    ll totalCost = 0;
    int edgesUsed = 0;

    for (const Edge& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            totalCost += edge.cost;
            edgesUsed++;
            if (edgesUsed == n - 1) break;  // We only need n-1 edges
        }
    }

    return totalCost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> pos(n), cost(n);
        for (int i = 0; i < n; i++) cin >> pos[i];
        for (int i = 0; i < n; i++) cin >> cost[i];

        cout << minimumConnectionCost(n, pos, cost) << endl;
    }

    return 0;
}
