#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> c;
vector<int> vis;
void dfs(int node, int &count, int color){
    vis[node]=1;
    count++;
    for(auto it:adj[node]){
        if(!vis[it] && c[it]==color){
            dfs(it,count,color);
        }
    }
}

int solve(vector<int> &from, vector<int> &to){
    int n=from.size()+1;

    adj.resize(n+1);
    for(int i=0;i<from.size();i++){
        adj[from[i]].push_back(to[i]);
        adj[to[i]].push_back(from[i]);
    }
    vis.resize(n+1,0);
    int ans=0;
    for(int i=1;i<=n;i++){
        int count=0;
        if(!vis[i]){
            dfs(i,count,c[i]);
        }
        if(count>=3){
            ans+=(count*(count-1))/2;
            ans-=(count-1);
        }
    }
    return ans;
}

int main(){
    int n; cin>>n;
    vector<int> to(n-1), from(n-1);
    for(int i=0;i<n-1;i++) cin>>from[i];
    for(int i=0;i<n-1;i++) cin>>to[i];
    c.resize(n+1);
    for(int i=1;i<n;i++) cin>>c[i];

   int ans=solve(from,to);
    cout<<ans<<endl; 
    return 0;
}