#include<bits/stdc++.h>
using namespace std;
// neural task allocation

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int m; cin>>m;
    map<int,int> mp;
    for(auto it:a) mp[it]++;
    int count=0;
    int rem=0;
    for(auto it:mp){
        if(it.second>=m) count+=m;
        else{
            rem+=it.second;
        }
    }
    count+=(rem/m);
    cout<<count<<endl;


    return 0;
}