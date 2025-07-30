#include<bits/stdc++.h>
using namespace std;
// maximum greatness

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int maxi=*max_element(a.begin(),a.end());
    sort(a.begin(),a.end());
    vector<int> b=a;

    int i=0, j=0;
    int count=0;
    while(i<n && j<n){
        if(b[j]>a[i]){
            count++; i++; j++;
        }
        else j++;
    }
    cout<<count<<endl;


    return 0;
}