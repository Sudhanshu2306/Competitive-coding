#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        cin>>a[i].second;
    }
    int m; cin>>m;
    vector<int> p(m);
    for(int i=0;i<m;i++) cin>>p[i];

    vector<int> ans(m);

    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            if(p[j]>=a[i].first && p[j]<=a[i].second){
                ans[j]++;
            }
        }
    }
    for(int i=0;i<m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
