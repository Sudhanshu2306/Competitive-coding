#include <bits/stdc++.h>
using namespace std;

pair<int,int> f(vector<vector<int>> a) {
    int n=a.size();
    if (n==0) return {-1,-1};
    int m=a[0].size();
    
    int maxi = 0;
    pair<int,int> ans={-1,-1};

    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            if(a[i][j]==1) {
                int size=1; 
                while(i-size>=0 && i+size<n && j-size>=0 && j+size<m &&
                       a[i-size][j-size]==1 && a[i-size][j+size]==1 &&
                       a[i+size][j-size]==1 && a[i+size][j+size]==1){
                    size++;
                }
                size--;
                
                if(size>maxi){
                    maxi=size;
                    ans={i,j};
                }
            }
        }
    }
    return ans;
}

int main(){
    

    return 0;
}
