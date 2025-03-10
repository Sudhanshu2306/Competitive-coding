#include<bits/stdc++.h>
using namespace std;

bool f(int n){
    vector<int> vis(10,0);
    while(n>0){
        if(vis[(n%10)]==1) return false;
        vis[(n%10)]=1;
        n/=10;
    }
    return true;
}

void countNumbers(vector<vector<int>> arr){
    vector<int> pre(1e5+1,0);
    for(int i=1;i<=1e5;i++){
        if(f(i)) pre[i]=pre[i-1]+1;
        else pre[i]=pre[i-1];
    }

    for(auto it:arr){
        int l=it[0], r=it[1];
        cout<<(pre[r]-pre[l-1])<<endl;
    }
}

int main(){
    int n; cin>>n;
    vector<vector<int>> a(n,vector<int>(2));
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++) cin>>a[i][j];
    }
    countNumbers(a);

    return 0;
}