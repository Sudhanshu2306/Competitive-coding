#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> ti;
int main(){
    int n,m; cin>>m;
    vector<int> to(m),from(m),w(m);
    for(int i=0;i<m;i++) cin>>from[i];
    for(int i=0;i<m;i++) cin>>to[i];
    for(int i=0;i<m;i++) cin>>w[i]; 

    cin>>n;
    vector<int> price(n+1);
    for(int i=1;i<=n;i++) cin>>price[i];

    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        adj[from[i]].push_back({to[i],w[i]});
        adj[to[i]].push_back({from[i],w[i]});
    }
    int src,dest; cin>>src>>dest;

    priority_queue<ti,vector<ti>,greater<ti>> pq;
    pq.push({0,src,price[src]});

    map<int,map<int,int>> best;
    best[src][price[src]]=0;
    while(!pq.empty()){
        auto [cost,node,p]=pq.top(); pq.pop();

        if(node==dest){
            cout<<cost<<endl; return 0;
        } 
        for(auto it:adj[node]){
            int ncost=cost+p*it.second;
            int np=min(p,price[it.first]);

            if(best[it.first].find(np)==best[it.first].end() || ncost<best[it.first][np]){
                best[it.first][np]=ncost;
                pq.push({ncost,it.first,np});
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}