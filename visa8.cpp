#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    int maxr=-1e9; int maxc=1e9;
    vector<pair<int,int>> rect;
    vector<bool> ans;
    for(int i=0;i<n;i++){
        int op; cin>>op;
        int x,y; cin>>x>>y;

        if(op==0){
            rect.push_back({x,y});
        }
        else{
            bool f=true;
            for(auto it:rect){
                int rw=it.first;
                int rh=it.second;

                if(!((rw<=x && rh<=y) ||(rh<=x && rw<=y))){
                    f=false; break;
                }
            }
            ans.push_back(f);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}