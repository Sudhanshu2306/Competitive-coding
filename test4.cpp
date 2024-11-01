#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int c1=0,c2=0,c3=0,ans=0;
    unordered_map<int,int> mp; 

    for(int i=0;i<n;i++){
        if(arr[i]==1) c1++;
        else if(arr[i]==2)c2++;
        else c3++;

        int d=c1-c3;

        if(c2>0 && mp.find(d)!=mp.end()) ans+=mp[d];
        mp[d]++;
    }
    cout<<ans<<endl;
    return 0;
}

// 1 1 2 3 3 1
// 1 2 3 2 3 1 1 3
// 1 2 1 3 2 3 1start
