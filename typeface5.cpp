#include<bits/stdc++.h>
using namespace std;

int dp[301][301];
int f(int i, int days, vector<int> &a){
    if(days==1){
        int maxi=0;
        for(int j=i;j<a.size();j++) maxi=max(maxi,a[j]);
        return maxi;
    }
    if(dp[i][days]!=-1) return dp[i][days];

    int mini=1e9;
    int maxi=0;
    for(int j=i;j<=a.size()-days;j++){
        maxi=max(maxi,a[i]);
        mini=min(mini,maxi+f(i+1,days-1,a));
    }
    return dp[i][days]=mini;
}

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int days; cin>>days;

    memset(dp,-1,sizeof(dp));

    int ans=f(0,days,a);
    cout<<ans<<endl;

    return 0;
}