#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> f(vector<vector<char>> a){
    int n=a.size(); int m=a[0].size();
    vector<vector<char>> ans(n,vector<char>(m,'-'));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='-' || a[i][j]=='#') ans[i][j]=a[i][j];
        }
    }
    int mini=1e9;
    for(int j=0;j<m;j++){
        int count=0;
        for(int i=0;i<n;i++){
            if(a[i][j]=='F') count=0;
            else if(a[i][j]=='-') count++;
            else if(a[i][j]=='#' || i==n-1){
                mini=min(mini,count);
            } 
        }
    }

    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            if(a[i][j]=='F') ans[i+mini][j]='F';
        }
    }
    return ans;
}

int main(){
    int n,m; cin>>n>>m;
    vector<vector<char>> a(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    cout<<endl;
    vector<vector<char>> ans=f(a);
    for(auto i:ans){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
    cout<<endl;

    return 0;
}