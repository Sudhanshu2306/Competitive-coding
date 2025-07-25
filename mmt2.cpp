#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int dp[100001][102];
int n,m;

int f(int i, int prev,vector<int> &a){
    if(i==a.size()) return 1;

    if(dp[i][prev+1]!=-1) return dp[i][prev+1];

    int ans=0;
    if(a[i]==0){
        if(prev==-1){
            for(int k=1;k<=m;k++) ans=(ans+f(i+1,k,a))%mod;
        }
        else{
           for(int val=prev-1;val<=prev+1;val++){
                if(val>=1 && val<=m){
                    ans=(ans+f(i+1,val,a))%mod;
                }
            }
        }
    }
    else{
        if(prev==-1 || abs(prev-a[i])<=1) ans=(ans+f(i+1,a[i],a))%mod;
        else ans=0;
    }
    return dp[i][prev+1]=ans%mod;
}
int main(){
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    memset(dp,-1,sizeof(dp));
    int ans=f(0,-1,a);
    cout<<ans<<endl;

    return 0;
}