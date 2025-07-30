#include<bits/stdc++.h>
using namespace std;

bool f(vector<int> &a){
    stack<int> st;
    int x=-1e9;
    for(auto it:a){
        if(it<x){
            return false;
        }
        while(!st.empty() && it>st.top()){
            x=st.top(); st.pop();
        }
        st.push(it);
    }
    return true;
}

int main(){
    int q; cin>>q;
    while(q--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        bool ans=f(a);
        if(ans) cout<<"YES ";
        else cout<<"NO ";
    }
    
    return 0;
}