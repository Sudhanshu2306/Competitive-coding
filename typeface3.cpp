#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int main(){
    string s; cin>>s;
    int t; cin>>t;

    vector<int> cnt(26,0);
    for(int i=0;i<s.size();i++) cnt[s[i]-'a']++;

    for(int i=0;i<t;i++){
        vector<int> temp(26,0);
        for(int j=0;j<26;j++){
            if(j==25){
                temp[0]=(temp[0]+cnt[j])%mod;
                temp[1]=(temp[1]+cnt[j])%mod;
            }
            else{
                temp[j+1]=(temp[j+1]+cnt[j])%mod;
            }
        }
        cnt=temp;
    }
    
    long long ans=0;
    for(auto it:cnt) ans=(ans+it)%mod;
    cout<<ans<<endl;
    return 0;
}