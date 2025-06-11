#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int &count){
    vis[node]=1;
    for(auto it:adj[node]){
        if(it!=node){
            if(!vis[it]){
                count++;
                dfs(it,adj,vis,count);
            } 
        }
    }
}

int solve(int n, vector<int> &from, vector<int> &to, vector<int> &f){
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u=from[i]-1, v=to[i]-1;
        if(abs(f[u]-f[v])<=1){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    int ans=0;
    vector<int> vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            int count=0;
            dfs(i,adj,vis,count);
            ans=max(count,ans);
        }
    }
    return ans;
}

int main(){
    int n; cin>>n;
    vector<int> from(n-1), to(n-1);
    for(int i=0;i<n-1;i++) cin>>from[i];
    for(int i=0;i<n-1;i++) cin>>to[i];
    vector<int> f(n);
    for(int i=0;i<n;i++) cin>>f[i];
    int ans=solve(n, from, to, f);
    cout<<ans<<endl;
    return 0;
}