#include<bits/stdc++.h>
using namespace std;

int f(int node, int parent, int h, vector<vector<int>> &adj, 
    vector<int> &a, int k, vector<vector<int>> &dp){
    if(h>31) return 0;
    if(dp[node][h]!=-1) return dp[node][h];

    int val=a[node];

    int type1=val-k;
    for(auto it:adj[node]){
        if(it!=parent) type1+=f(it,node,h,adj,a,k,dp);
    }
    int type2=val/2;
    for(auto it:adj[node]){
        if(it!=parent) type2+=f(it,node,h+1,adj,a,k,dp);
    }

    return dp[node][h]=max(type1,type2);
}

int main(){
    int n; cin>>n;
    int m; cin>>m;
    vector<int> from(m), to(m);
    for(int i=0;i<m;i++) cin>>from[i];
    for(int i=0;i<m;i++) cin>>to[i];

    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u=from[i], v=to[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int k; cin>>k;

    vector<vector<int>> dp(n,vector<int>(32,-1));

    int ans=f(0,-1,0,adj,a,k,dp);
    cout<<ans<<endl;

    return 0;
}