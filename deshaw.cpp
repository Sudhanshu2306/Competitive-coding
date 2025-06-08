#include<bits/stdc++.h>
using namespace std;

int ff(vector<int> &a, int i, int prev, vector<vector<int>> &dp){
    int n=a.size();
    if(i==n) return a[prev];
    if(i==n-1) return max(a[prev],a[i]);
    if(i==n-2) return max({a[n-1],a[n-2],a[prev]})+min({a[n-1],a[n-2],a[prev]});

    if(dp[i][prev]!=-1) return dp[i][prev];
    int f=a[prev];
    int s=a[i];
    int t=a[i+1];
    int ans=INT_MAX;
    ans=min({ans,max(f,s)+ff(a,i+2,i+1,dp),max(s,t)+ff(a,i+2,prev,dp),max(f,t)+ff(a,i+2,i,dp)});

    return dp[i][prev]=ans;
}

int solve(vector<int> &nums){
    int n=nums.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return ff(nums,0,1,dp);
}

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int ans=solve(a);
    cout<<ans<<endl;
    return 0;
}