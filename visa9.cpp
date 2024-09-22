#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,t; cin>>n>>t;
    vector<int> a(n);
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        mp[a[i]]++;
    }
    vector<int> b(t);
    for(int i=0;i<t;i++) cin>>b[i];

    int m; cin>>m;
    vector<int> ans;
    for(int i=0;i<m;i++){
        int x; cin>>x;
        if(x==0){
            int k,x; cin>>k>>x;
            b[k]+=x;
        }
        else{
            int x; cin>>x;
            int count=0;
            for(int j=0;j<t;j++){
                if(mp.find(x-b[j])!=mp.end()) count+=mp[x-b[j]];
            }
            ans.push_back(count);
        }
    }

    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";

    return 0;
}


