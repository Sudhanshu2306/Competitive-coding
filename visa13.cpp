#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<string> a(n);

    map<int,int> mp;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        string x=a[i].substr(5,2);
        int y=stoi(x);
        mp[y]++;
    }
    int ans=-1e9;
    int maxi=-1;
    for(auto i:mp){
        if(ans<i.second){
            ans=i.second;
            maxi=i.first;
        }
    }
    cout<<maxi<<endl;

    return 0;
}

