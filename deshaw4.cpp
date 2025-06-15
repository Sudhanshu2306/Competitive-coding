#include<bits/stdc++.h>
using namespace std;

vector<int> f(string s){
    int n=s.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        int x=0;
        for(int j=i;j<n;j++){
            x=x*10+(s[j]-'0');
            ans.push_back(x);
        }
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    return ans;
}

vector<int> solve(vector<string> &a){
    int n=a.size();
    int prev=0;
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        if(a[i].size()==1){
            int x=a[i][0]-'0';
            if(x<prev) return {-1};
            ans[i]=x;
            prev=x;
        }
        else{
            // generating all substrings in sorted order
            vector<int> st=f(a[i]);
            auto it=lower_bound(st.begin(),st.end(),prev);
            if(it==st.end()) return {-1};
            ans[i]=*it;
            prev=*it;
        }
    }
    return ans;
}

int main(){
    int n; cin>>n;
    vector<string> a(n); 
    for(int i=0;i<n;i++) cin>>a[i];

    vector<int> ans=solve(a);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}