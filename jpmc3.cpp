#include<bits/stdc++.h>
using namespace std;

void nextGreater(string s){
    int n=s.size();
    int pi;
    for(int i=n-1;i>0;i--){
        if(s[i]>s[i-1]){
            pi=i; break;
        }
    }
    if(pi!=0){
        for(int i=n-1;i>=pi;i--){
            if(s[i]>s[pi-1]){
                swap(s[i],s[pi-1]); break;
            }
        }
    }

    for(int i=n-1;i>pi;i--){
        swap(s[i],s[pi]); pi++;
    }
    cout<<s<<endl;
}

int main(){
    string s; cin>>s;
    solve(s);

    return 0;
}