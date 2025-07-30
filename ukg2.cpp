#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
vector<vector<pair<int,int>>> adj;
int main(){
    int n; cin>>n;
    adj.resize(n);

    for(int i=0;i<n-1;i++){
        int u,v,wt; cin>>u>>v>>wt;
        u--; v--;
        adj[u].push_back({v,wt});
    }
    int x; cin>>x;

    vector<int> ans(n,0);
    ans[0]=1*x;
    queue<int> q; q.push(0);
    while(!q.empty()){
        auto node=q.front(); q.pop();
        for(auto it:adj[node]){
            ans[it.first]=(1LL*ans[node]*it.second)%mod;
            q.push(it.first);
        }
    }
    for(auto it:ans) cout<<it<<" ";
    
    return 0;
}