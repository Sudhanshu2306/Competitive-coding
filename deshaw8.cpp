#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &a){
    int n=a.size();
    int count=0;
    
    vector<int> pre(n), suf(n);
    pre[0]=suf[n-1]=1;
    for(int i=1;i<n;i++) pre[i]=pre[i-1] && (a[i]>=a[i-1]);
    for(int i=n-2;i>=0;i--) suf[i]=suf[i+1] && (a[i]<=a[i+1]);

    for(int i=0;i<n-1;i++){
        if(pre[i]) count++;
    }
    for(int i=1;i<n;i++){
        if(suf[i]) count++;
    }
    int r=0;
    while(r<n && suf[r]==0){
        r++;
    }
    for(int i=0;i<n-1;i++){
        if(pre[i]==1){
            r=max(r,i+2);

            while(r<n && a[i]>a[r]) r++;
            if(r<n) count+=(n-r);
            else break;
        }
    }
    return count;

}

int main(){
    int n; cin>>n; vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int ans=solve(a);
    cout<<ans<<endl;
    return 0;
}