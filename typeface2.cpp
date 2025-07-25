#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> values;

int dfs(int node, int parent, int &maxi){
    int first=0,second=0;
    int x=0;
    for(auto it:adj[node]){
        if(it!=parent){
            int child=dfs(it,node,maxi);
            if(child>first){
                second=first;
                first=child;
            }
            else if(child>second) second=child;
        }
    }
    maxi=max(maxi,values[node]+first+second);
    return values[node]+first;
}

int main(){
    int n; cin>>n;
    vector<int> parent(n);
    for(int i=0;i<n;i++) cin>>parent[i];

    values.resize(n);
    for(int i=0;i<n;i++) cin>>values[i];

    int maxi=-1e9;
    adj.resize(n);
    for(int i=1;i<n;i++){
        adj[i].push_back(parent[i]);
        adj[parent[i]].push_back(i);
    }

    dfs(0,-1,maxi);
    cout<<maxi<<endl;

    return 0;
}