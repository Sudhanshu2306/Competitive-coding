#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll bi_exp(ll a, ll b){
    ll ans=1;
    while(b>0){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b/=2;
    }
    return ans;
}
vector<ll> fact, infact;
ll nCr(ll a, ll b){
    if(b>a) return 0;
    return (fact[a]*infact[a-b])%mod;
}
ll ans=1;
void dfs(ll m, ll node, ll parent, vector<vector<ll>> &adj, vector<ll> &vis){
    vis[node]=1;
    ll count=0;
    for(auto it:adj[node]){
        if(it!=parent){
            count++;
        }
    }
    if(parent==-1){
        ans=(ans*m)%mod;
        ans=(ans*nCr(m-1,count))%mod;
    }
    else{
        ans=(ans*nCr(m-2,count))%mod;
    }
    for(auto it:adj[node]){
        if(it!=parent) dfs(m,it,node,adj,vis);
    }
}
ll solve(ll n, ll m, vector<ll> &from, vector<ll> &to){
    vector<vector<ll>> adj(n+1);
    for(ll i=0;i<n-1;i++){
        ll u=from[i], v=to[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll x=max(n,m)+1;
    fact.resize(x,1);
    for(ll i=1;i<x;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    infact.resize(x,1);
    infact[x-1]=bi_exp(fact[x-1],mod-2);

    for(ll i=x-1;i>0;i--){
        infact[i-1]=(infact[i]*i)%mod;
    }
    vector<ll> vis(n+1,0);
    dfs(m,1,-1,adj,vis);

    return ans;
}

int main(){
    ll m; cin>>m;
    ll n; cin>>n;

    vector<ll> from(n-1), to(n-1);
    for(ll i=0;i<n-1;i++) cin>>from[i];
    for(ll i=0;i<n-1;i++) cin>>to[i];

    ll ans=solve(n,m,from,to);
    cout<<ans<<endl;
    return 0;
}