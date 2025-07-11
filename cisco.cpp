#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &coins, vector<int> &from, vector<int> &to){
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        adj[from[i]].push_back(to[i]);
        adj[to[i]].push_back(from[i]);
    }

    queue<int> q;
    
}

int main(){
    int n; cin>>n;
    vector<int> coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];

    vector<int> tree_from(n-1), tree_to(n-1);
    for(int i=0;i<n-1;i++) cin>>tree_from[i];
    for(int i=0;i<n-1;i++) cin>>tree_to[i];

    int ans=solve(n, coins, tree_from, tree_to);
    cout<<ans<<endl;
    return 0;
}