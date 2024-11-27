#include <bits/stdc++.h>
using namespace std;

bool ff(string s) {
    vector<vector<int>> dir={{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    int x=0, y=0; 
    int dir=0;

    for(char it:s) {
        if (it=='G') {
            x+=dir[dir][0];
            y+=dir[dir][1];
        } 
        else if(it=='L') dir=(dir+1)%4;
        else if(it=='R') dir=(dir+3)%4;
    }
    return (x==0 && y==0) || dir!=0;
}

int main() {
    int n; cin>>n;
    vector<string> a(n);
    
    for(int i=0;i<n;i++) cin>>a[i];
    
    for(int i=0;i<n;i++){
        if (ff(a[i])) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
