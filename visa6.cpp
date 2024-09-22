#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> b(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>b[i][j];
        }
    }
    int x; cin>>x;
    vector<pair<int,int>> op(x);
    for(int i=0;i<x;i++){
        cin>>op[i].first;
        cin>>op[i].second;
    }
    int dx[4]={-1,1,-1,1};
    int dy[4]={-1,-1,1,1};

    for(int z=0;z<x;z++){
        int i=op[z].first;
        int j=op[z].second;
        int curr=b[i][j];
        for(int k=0;k<4;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && b[nr][nc]==curr && curr!=0){
                b[nr][nc]=0;
            }
        }
        b[i][j]=0;
        for(int c=0;c<m;c++){
            for(int r=n-1;r>0;r--){
                if(b[r][c]==0){
                    if(r-1>=0) {
                        b[r][c]=b[r-1][c];
                        b[r-1][c]=0;
                    }
                }
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}


