#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,x;
    cin>>s>>x;

    string ans="";
    int i=0;
    int j=0;

    int maxi=max(s.size(),x.size());
    int mini=min(s.size(),x.size());
    int diff=maxi-mini;
    if(maxi==s.size()){
        while(diff--){
            ans+=s[i];
            i++;
        }
    }
    else{
        while(diff--){
            ans+=x[j];
            j++;
        }
    }
    while(i<s.size() && j<x.size()){
        int sum=(s[i]-'0')+(x[j]-'0');
        ans+=to_string(sum);
        i++;j++;
    }
    cout<<ans<<endl;

    return 0;
}