#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
vector<int> fact, infact;
int modPow(int a, int b){
    int ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b/=2;
    }
    return ans;
}
vector<int> solve(int k, vector<pair<int,int>> &q){
    int n=q.size();
    vector<int> a;
    int maxi=0;
    for(auto it:q) maxi=max(maxi,it.second);
    
    vector<int> dp(maxi+1,0), pre(maxi+1,0);
    dp[0]=1;
    for(int i=1;i<=maxi;i++){
        dp[i]=dp[i-1];
        if(i>=k) dp[i]=(dp[i]+dp[i-k])%mod;
    }
    pre[0]=1;
    for(int i=1;i<=maxi;i++){
        pre[i]=(pre[i-1]+dp[i])%mod;
    }

    for(auto it:q){
        int l=it.first, r=it.second;
        int ans=pre[r];
        if(l>0) ans=(ans-pre[l-1]+mod)%mod;
        a.push_back(ans);
    }

    return a;
}

int main(){
    int k; cin>>k;

    int n; cin>>n;
    vector<pair<int,int>> a(n); 
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;

    vector<int> ans=solve(k,a);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<endl;
    // cout<<endl;

    return 0;
}