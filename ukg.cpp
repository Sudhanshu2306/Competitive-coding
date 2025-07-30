#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    int n=s.size();

    vector<int> cnt(26,0);
    for(auto it:s) cnt[it-'a']++;

    int gcd=0;
    for(auto it:cnt){
        if(it>0) gcd=(gcd==0?it:__gcd(gcd,it));
    }
    int ans=0;
    for(auto it:cnt){
        if(it>=gcd){
            ans+=(it/gcd);
        }
    }
    cout<<ans<<endl;
    return 0;
}