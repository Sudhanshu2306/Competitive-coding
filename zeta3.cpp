#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int i=0,j=0;
    int maxi=0;
    map<int,int> mp;
    int sum=0;
    while(j<n){
        while(mp.find(a[j])==mp.end() && sum+a[j]<=k){
            mp[a[j]]++; sum+=a[j]; j++;
        } 
        maxi=max(maxi,j-i+1);
        mp.erase(a[i]); sum-=a[i];
        i++;
    }
    cout<<maxi<<endl;
    return 0;
}