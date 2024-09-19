#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m; cin>>m;
    vector<int> p(m);

    string y="";
    for(int i=0;i<m;i++){
        cin>>p[i];
        if(p[i]==-1){
            y+="2";
        }
        else if(p[i]==1) y+="1";
        else y+="0";

    }
    cout<<y<<endl;
    string x="";
    for(int i=1;i<n;i++){
        if(a[i-1]<a[i]) x+="1";
        else if(a[i-1]==a[i]) x+="0";
        else if(a[i-1]>a[i]) x+="2";
    }
    cout<<x<<endl;
    int count=0;
    for(int i=0;i<=n-m-1;i++){
        if(x.substr(i,m)==y) count++;
    }
    // cout<<count<<endl;


    return 0;
}