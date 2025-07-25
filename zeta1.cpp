#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int count=0;
    int tot=(n*(n+1))/2;

    int i=0,j=0;
    map<int,int> mp;
    while(j<n){
        while(j<n && mp[a[j]]+1<k){
            mp[a[j]]++;
            j++;
        }
        count+=(j-i);
        if(i<j){
            mp[a[i]]--;
            if(mp[a[i]]==0) mp.erase(a[i]);
            i++;
        }
    }
    cout<<tot-count<<endl;

    return 0;
}