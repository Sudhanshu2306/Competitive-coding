#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    int p; cin>>p;
    vector<pair<double,int>> x;
    for(int i=0;i<n;i++){
        double z=(1.0*a[i]/b[i]);
        x.push_back({z,b[i]*2});
    }
    sort(x.begin(),x.end(),[](pair<double,int> &a, pair<double,int> &b){
        if(a.first!=b.first) return a.first>b.first;
        return a.second>b.second;
    });

    // for(auto it:x) cout<<it.first<<" "<<it.second<<endl;

    int ans=0;
    for(auto it:x){
        if(it.second<=p){
            int z=it.first*(it.second/2);
            // cout<<z<<" ";
            ans+=z;
            p-=it.second;
        }
    }
    cout<<ans<<endl;

    return 0;
}