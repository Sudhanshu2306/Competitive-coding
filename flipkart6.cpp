#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge{
    int to, nxt, cap, cost;
};

class MinCost{
    int n, src, snk;
    vector<int> head;
    vector<Edge> edges;

    void addEdgeIn(int u, int v, int cap, int cost){
        edges.push_back({v, head[u], cap, cost});
        head[u] = (int)edges.size() - 1;
    }

public:
    MinCost(int N, int S, int T) : n(N), src(S), snk(T), head(N, -1){
        edges.reserve(8000000); 
    }
    void addEdge(int u, int v, int cap, int cost){
        addEdgeIn(u, v, cap, cost);
        addEdgeIn(v, u, 0, -cost); 
    }
    ll solve(int flowLim){
        const ll INF = 4e18;
        vector<ll> dist(n), pot(n, 0);
        vector<int> pv(n), pe(n);
        ll cost = 0;
        int flow = 0;

        while (flow < flowLim){
            fill(dist.begin(), dist.end(), INF);
            dist[src] = 0;
            priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
            pq.push({0, src});
            while (!pq.empty()){
                auto [d, u] = pq.top();
                pq.pop();
                if (d != dist[u])
                    continue;
                for (int ei = head[u]; ei != -1; ei = edges[ei].nxt){
                    Edge &e = edges[ei];
                    if (!e.cap) continue;
                    ll nd = d + e.cost + pot[u] - pot[e.to];
                    if (nd < dist[e.to]){
                        dist[e.to] = nd;
                        pv[e.to] = u;
                        pe[e.to] = ei;
                        pq.push({nd, e.to});
                    }
                }
            }
            if (dist[snk] == INF) break; 
            for (int v = 0; v < n; ++v)
                if (dist[v] < INF) pot[v] += dist[v];

            int add = flowLim - flow;
            for (int v = snk; v != src; v = pv[v]){
                add = min(add, edges[pe[v]].cap);
            }
            for (int v = snk; v != src; v = pv[v]){
                int ei = pe[v];
                edges[ei].cap -= add;
                edges[ei ^ 1].cap += add; g
            }
            flow += add;
            cost += 1LL * add * pot[snk];
        }
        return cost; 
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    if (!(cin >> N >> K)) return 0;

    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};

    vector<int> val(N * N);
    ll totalSum = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j){
            int x; cin >> x;
            val[i * N + j] = x;
            totalSum += x;
        }

    int V = N * N + 2;
    int SRC = V - 2, SNK = V - 1;
    MinCost mcmf(V, SRC, SNK);

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            int id = i * N + j;
            bool black = ((i + j) & 1) == 0;
            if (black) mcmf.addEdge(SRC, id, 1, 0);
            else mcmf.addEdge(id, SNK, 1, 0);

            if (!black) continue;
            for (int dir = 0; dir < 4; dir++) {
                int ni = i + dx[dir], nj = j + dy[dir];
                if (ni < 0 || ni >= N || nj < 0 || nj >= N)
                    continue;
                int nid = ni * N + nj;
                int w = -(val[id] + val[nid]);
                mcmf.addEdge(id, nid, 1, w);
            }
        }
    }

    ll minCost = mcmf.solve(K);
    ll visible = totalSum + minCost;
    cout << visible << '\n';
    return 0;
}