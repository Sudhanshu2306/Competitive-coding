#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int f(int i, int p, vector<int> &a, vector<int> &b){
    if(i==a.size() || p==0) return 0;

    if(dp[i][p]!=-1) return dp[i][p];
    int take=0;
    if(p-2*a[i]>=0){
        take=b[i]+f(i+1,p-2*a[i],a,b);
    } 
    int nottake=f(i+1,p,a,b);

    return dp[i][p]=max(take,nottake);
}

int main(){
    int n; cin>>n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++) cin>>a[i];

    int p; cin>>p;
    memset(dp,-1,sizeof(dp));
    int ans=f(0,p,a,b);
    cout<<ans<<endl;

    return 0;
}