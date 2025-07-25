#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int src,dest; cin>>src>>dest;

    int stop_count; cin>>stop_count;
    int routes; cin>>routes;

    vector<tuple<int,int,int>> a;
    for(int i=0;i<routes;i++){
        int x,y,z; cin>>x>>y>>z;
        a.push_back({x,y,z});
    }
    vector<vector<pair<int,int>>> adj(n);
    for(auto it:a){
        auto [u,v,wt]=it;
        adj[u].push_back({v,wt});
    }
    vector<int> dist(n,1e9);
    queue<pair<int,int>> q;
    q.push({src,0});

    int count=0;
    while(!q.empty() && count<=stop_count){
        int x=q.size();
        while(x--){
            auto [node,cost]=q.front(); q.pop();

            for(auto [v,wt]:adj[node]){
                if (wt+cost<dist[v]){
                    dist[v]=wt+cost;
                    q.push({v,dist[v]});
                }
            }
        }
        count++;
    }
    int ans=(dist[dest]==1e9)?-1:dist[dest];
    cout<<ans<<endl;

    return 0;
}