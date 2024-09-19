#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<vector<int>> a(3,vector<int>(n));
    for(int i=0;i<n;i++){
        cin>>a[0][i];
    } 
    for(int i=0;i<n;i++){
        cin>>a[1][i];
    } 
    for(int i=0;i<n;i++){
        cin>>a[2][i];
    } 
    for(int i=0;i<n;i++){
        sort(a[i].begin(),a[i].end());
    }
    sort(a.begin(),a.end());
    int count=1;
    for(int i=0;i<n-1;i++){
        if(a[i][2]>a[n-1][1] && a[i][1]>a[n-1][0]) count++;
    }
    cout<<count<<endl;
    return 0;
}