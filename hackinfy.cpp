#include <bits/stdc++.h>
using namespace std;
static const int mod = 1e9+7;

struct Fenwick{
    int n;
    vector<int> f;
    Fenwick(int _n): n(_n), f(n+1,0) {}
    void update(int i, int v){
        for(; i <= n; i += i & -i)
            if((f[i]+=v)>=mod) f[i]-=mod;
    }
    int query(int i){
        int s=0;
        for(; i > 0; i -= i & -i)
            if((s+=f[i])>=mod) s-=mod;
        return s;
    }
    int rangeQuery(int l, int r){
        if(l>r) return 0;
        int ans=query(r)-query(l-1);
        if(ans<0) ans+=mod;
        return ans;
    }
};

int N;
vector<vector<int>> adj;

vector<int> dd, ud, beauty;
long long answer=0;
vector<int> comp;

void dfs1(int u,int p){
    dd[u]=0;
    for(int v:adj[u]) if(v!=p){
        dfs1(v,u);
        dd[u]=max(dd[u], dd[v]+1);
    }
}

Fenwick *bit;
void dfs2(int u,int p){
    int best1=-1,best2=-1;
    for(int v:adj[u]) if(v!=p){
        int d = dd[v];
        if(d>best1){ 
            best2=best1; 
            best1=d; 
        }
        else if(d>best2) best2=d; 
    }

    for(int v:adj[u]) if(v!=p){
        int use=(dd[v]==best1 ? best2:best1);
        ud[v]=1+max(ud[u],(use<0?-1:use+1));
        dfs2(v,u);
    }
}

void dfsCount(int u,int p){
    int idx=int(lower_bound(comp.begin(),comp.end(),beauty[u])-comp.begin())+1;
    int sumGT=bit->rangeQuery(idx+1, comp.size());
    int dp=1+sumGT; if(dp>=mod) dp-=mod;

    bit->update(idx, dp);
    answer=(answer+dp)%mod;
    for(int v:adj[u]) if(v!=p) dfsCount(v,u);

    bit->update(idx, mod-dp);
}

void solve(int M, vector<int> &parent){
    for(int i=1;i<=M;i++){
        int u = i+1;
        int p = parent[i];
        adj[u].push_back(p);
        adj[p].push_back(u);
    }
    N=M+1;
    dd.assign(N+1,0);
    ud.assign(N+1,0);

    dfs1(1,0);
    ud[1]=0;
    dfs2(1,0);

    beauty.assign(N+1,0);
    comp.reserve(N);

    for(int u=1;u<=N;u++){
        vector<int> br;
        br.push_back(ud[u]);
        for(int v: adj[u]){
            if(parent[v-1]==u || (u==1 && v!=1))
                br.push_back(dd[v]+1);
        }
        sort(br.begin(), br.end(), greater<int>());
        int b1 = br[0];
        int b2 = br.size()>1 ? br[1] : 0;
        beauty[u] = b1 + b2 + 1;
        comp.push_back(beauty[u]);
    }

    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    bit = new Fenwick(comp.size());
    dfsCount(1,0);

    cout<<answer<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int M; cin>>M;
    N=M+1;
    
    vector<int> parent(M+1);
    adj.assign(N+1,{});
    for(int i=1;i<=M;i++){
        cin>>parent[i];
    }

    solve(M,parent);
    return 0;
}
