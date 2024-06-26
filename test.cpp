#include <bits/stdc++.h>
using namespace std;

string GetOriginalString(string s){
    vector<int>main_map(26,0);
    for(auto it:s){
        if(it!='i'){
            main_map[it-'a']++;
        }
    }
    for(auto it:main_map){
        if(it%2==1) return "notpossible";
    }
    vector<int>cur_map(26,0);
    int ind=0;
    for(int i=0;i<s.size();++i){
        char it=s[i];
        if(it!='i'){
            cur_map[it-'a']++;
        }
        bool flag=true;
        for(int k=0;k<26;k++){
            if(cur_map[k]*2!=main_map[k]){
                flag=false;
                break;
            }
        }
        if(flag){
            ind=i;
            break;
        }
    }
    int upper_reach=ind+1;
    while(s[upper_reach]=='i'){
        upper_reach++;
    }
    string ans=s.substr(0,upper_reach);
    return ans;
}
int main(){
    string s;cin>>s;
    string ans=GetOriginalString(s);
    cout<<ans<<"\n";

    return 0;
}