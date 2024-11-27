#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        long long n, d, l;
        cin>>n>>d>>l;
        if(d ==1){
            if(n ==2 && l ==2){
                cout<<"1 2\n";
            }
            else{
                cout<<"-1\n";
            }
        }
        else if(d ==2){
            if(l ==n-1 && n >=3){
                string s="";
                for(int i=2;i<=n;i++) s += to_string(1)+" "+to_string(i)+"\n";
                cout<<s;
            }
            else{
                cout<<"-1\n";
            }
        }
        else{
            if( (l >=2 && l <=n - d +1 && n >= d+1)){
              
                if(l > 2 + (d-1)*(n - d -1 >=0 ? n - d -1 : 0)){
                    cout<<"-1\n";
                    continue;
                }
                vector<pair<int, int>> edges;
            
                for(int i=1;i<=d;i++) edges.emplace_back(i, i+1);
            
                int next_node = d +1;
               
                queue<int> q;
                for(int i=2;i<=d;i++) q.push(i);
               
                int required_leaves = l -2;
          
                for(int i=0;i<required_leaves && next_node <n;i++, next_node++){
                    if(q.empty()){
                        break;
                    }
                    int parent = q.front();
                    edges.emplace_back(parent, next_node+1);
                    q.push(next_node+1);
                }
                
                while(next_node <n){
                    if(q.empty()){
                        break;
                    }
                    int parent = q.front();
                    q.pop();
                    edges.emplace_back(parent, next_node+1);
                    q.push(next_node+1);
                    next_node++;
                }
                if(next_node !=n){
                    cout<<"-1\n";
                    continue;
                }
                
                vector<int> degree(n+2,0);
                for(auto &[u, v]: edges){
                    degree[u]++;
                    degree[v]++;
                }
                int leaf_count =0;
                for(int i=1;i<=n;i++) if(degree[i]==1) leaf_count++;
                if(leaf_count !=l){
                    cout<<"-1\n";
                    continue;
                }
              
                auto bfs = [&](int start) -> pair<int, int> {
                    vector<int> dist(n+1, -1);
                    queue<int> qq;
                    qq.push(start);
                    dist[start]=0;
                    int farthest = start;
                    while(!qq.empty()){
                        int u = qq.front(); qq.pop();
                        for(auto &[x, y] : edges){
                            if(x ==u && dist[y]==-1){
                                dist[y]=dist[u]+1;
                                qq.push(y);
                                if(dist[y] > dist[farthest]) farthest = y;
                            }
                            else if(y ==u && dist[x]==-1){
                                dist[x]=dist[u]+1;
                                qq.push(x);
                                if(dist[x] > dist[farthest]) farthest = x;
                            }
                        }
                    }
                    return {farthest, dist[farthest]};
                };
                pair<int, int> first = bfs(1);
                pair<int, int> second = bfs(first.first);
                if(second.second !=d){
                    cout<<"-1\n";
                    continue;
                }
               
                string s="";
                for(auto &[u, v]: edges) s += to_string(u)+" "+to_string(v)+"\n";
                cout<<s;
            }
            else{
                cout<<"-1\n";
            }
        }
    }
}