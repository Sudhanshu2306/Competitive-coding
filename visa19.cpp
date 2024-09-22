#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> fish(n);
    for(int i=0;i<n;i++){
        cin>>fish[i];
    }
    int m; cin>>m;
    vector<int> baits(m);
    for(int i=0;i<m;i++) cin>>baits[i];

    sort(fish.begin(),fish.end());
    sort(baits.begin(),baits.end());

    int i=0,j=0;
    int count=0;
    int ans=0;
    while(i<n && j<m){
        if(baits[j]<fish[i]){
            count++; i++;
            ans++;
        }
        else{
            i++;
        }
        if(count==3){
            j++; count=0;
        }
    }
    cout<<ans<<endl;

    return 0;
}

