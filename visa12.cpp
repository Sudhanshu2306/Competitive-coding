#include <bits/stdc++.h>
using namespace std;

int f(vector<vector<int>> a, int n, int y, int bg){
    int changes=0;
    int center=n/2;

    for(int i=0;i<=center;i++){
        if(a[i][i]!=y) changes++;
        if(a[i][n-i-1]!=y) changes++;
    }
    for(int i=center;i<n;i++){
        if(a[i][center]!=y) changes++;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<=center && (j==i || j==n-i-1) || (i>=center && j==center)) continue;
            if(a[i][j]!=bg) changes++;
        }
    }
    return changes;
}

int main(){
    int n; cin>>n;
    vector<vector<int>> a(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    int mini=1e9;
    vector<pair<int,int>> x={{0,1},{0,2},{1,0},{1,2},{2,0},{2,1}};

    for(auto it:x){
        int y=it.first;
        int bg=it.second;
        int ans=f(a,n,y,bg);
        mini=min(mini,ans);
    }

    cout<<mini<<endl;

    return 0;
}

