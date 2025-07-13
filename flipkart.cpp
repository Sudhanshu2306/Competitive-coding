#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Seg
{
    ll sum, pref, suff, best;
};

Seg mergeSeg(const Seg &a, const Seg &b)
{
    Seg res;
    res.sum = a.sum + b.sum;
    res.pref = max(a.pref, a.sum + b.pref);
    res.suff = max(b.suff, b.sum + a.suff);
    res.best = max({a.best, b.best, a.suff + b.pref});
    return res;
}

Seg reverseSeg(Seg s){
    swap(s.pref, s.suff); return s;
}

class SegTree{
    vector<Seg> t;
    int n;
    void build(int p, int l, int r, const vector<ll> &a){
        if (l == r){
            ll v = a[l];
            t[p] = {v, v, v, v};
            return;
        }
        int m = (l + r) >> 1;
        build(p << 1, l, m, a);
        build(p << 1 | 1, m + 1, r, a);
        t[p] = mergeSeg(t[p << 1], t[p << 1 | 1]);
    }
    Seg query(int p, int l, int r, int ql, int qr) const
    {
        if (ql <= l && r <= qr)
            return t[p];
        int m = (l + r) >> 1;
        if (qr <= m)
            return query(p << 1, l, m, ql, qr);
        if (ql > m)
            return query(p << 1 | 1, m + 1, r, ql, qr);
        return mergeSeg(query(p << 1, l, m, ql, qr), query(p << 1 | 1, m + 1, r, ql, qr));
    }

public:
    SegTree(const vector<ll> &a){
        n = a.size();
        t.resize(n << 2);
        build(1, 0, n - 1, a);
    }
    Seg query(int l, int r) const { return query(1, 0, n - 1, l, r); }
};

const int MAXN = 100000;
vector<int> g[MAXN + 1];
int parentArr[MAXN + 1], depthArr[MAXN + 1], heavy[MAXN + 1], head[MAXN + 1], pos[MAXN + 1], sub[MAXN + 1];
int curPos;

int dfs1(int u, int p){
    parentArr[u] = p;
    sub[u] = 1;
    int mx = 0;
    for (int v : g[u])
        if (v != p){
            depthArr[v] = depthArr[u] + 1;
            int sz = dfs1(v, u);
            sub[u] += sz;
            if (sz > mx){
                mx = sz;
                heavy[u] = v;
            }
        }
    return sub[u];
}

void dfs2(int u, int h, const vector<ll> &val, vector<ll> &base)
{
    head[u] = h;
    pos[u] = curPos;
    base[curPos] = val[u];
    ++curPos;
    if (heavy[u])
        dfs2(heavy[u], h, val, base);
    for (int v : g[u])
        if (v != parentArr[u] && v != heavy[u])
            dfs2(v, v, val, base);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    for (int i = 1; i <= N; ++i){
        g[i].clear();
        heavy[i] = 0;
    }
    for (int i = 0; i < N - 1; ++i){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> val(N + 1);
    for (int i = 1; i <= N; ++i) cin >> val[i];

    depthArr[1] = 0;
    dfs1(1, 0);
    vector<ll> base(N);
    curPos = 0;
    dfs2(1, 1, val, base);

    SegTree st(base);

    int Q;
    cin >> Q;
    while (Q--){
        int u, v;
        cin >> u >> v;
        vector<Seg> leftSegs, rightSegs;
        while (head[u] != head[v]){
            if (depthArr[head[u]] >= depthArr[head[v]]){
                Seg seg = st.query(pos[head[u]], pos[u]);
                leftSegs.push_back(reverseSeg(seg));
                u = parentArr[head[u]];
            }
            else{
                Seg seg = st.query(pos[head[v]], pos[v]);
                rightSegs.push_back(seg);
                v = parentArr[head[v]];
            }
        }
        if (depthArr[u] >= depthArr[v]){
            Seg seg = st.query(pos[v], pos[u]);
            leftSegs.push_back(reverseSeg(seg));
        }
        else{
            Seg seg = st.query(pos[u], pos[v]);
            rightSegs.push_back(seg);
        }

        Seg res;
        bool first = true;
        for (const Seg &s : leftSegs){
            if (first){
                res = s;
                first = false;
            }
            else res = mergeSeg(res, s);
        }
        for (int i = (int)rightSegs.size(); i--;){
            const Seg &s = rightSegs[i];
            if (first){
                res = s;
                first = false;
            }
            else res = mergeSeg(res, s);
        }
        cout << res.best << '\n';
    }
    return 0;
}