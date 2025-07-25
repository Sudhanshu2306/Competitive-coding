#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<string> a(n),b(n);

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(a[i].size()==b[i].size()){
            map<int,int> mp;
            for(auto it:a[i]) mp[it]++;
            int count=0;
            for(auto it:b[i]){
                if(mp.find(it)!=mp.end()){
                    mp[it]--;
                    if(mp[it]==0) mp.erase(it);
                } 
                // else count++;
            }
            for(auto it:mp) count+=it.second;
            ans.push_back(count);
        }
        else ans.push_back(-1);
    }
    for(auto it:ans) cout<<it<<" ";

    return 0;
}