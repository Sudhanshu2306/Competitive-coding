#include<bits/stdc++.h>
using namespace std;
vector<int> vis;
vector<int> opc_node;
int ans=0;

int dfs(int node, vector<vector<int>> &adj, int k){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]) opc_node[node]+=dfs(it,adj,k);
    }
    if(node==1) return 0;
    ans+=ceil((opc_node[node]+k-1)/k);
    return opc_node[node];
}

int solve(int n, vector<int> &from, vector<int> &to, int k){
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        adj[from[i]].push_back(to[i]);
        adj[to[i]].push_back(from[i]);
    }
    vis.resize(n+1,0);
    opc_node.resize(n+1,1);
    dfs(1,adj,k);
    return ans;
}

int main(){
    int n; cin>>n;
    vector<int> from(n-1), to(n-1);
    for(int i=0;i<n-1;i++) cin>>from[i];
    for(int i=0;i<n-1;i++) cin>>to[i];

    int k; cin>>k;

    int ans=solve(n, from, to, k);
    cout<<ans<<endl;
    

    return 0;
}