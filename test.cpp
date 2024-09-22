#include<bits/stdc++.h>
using namespace std;

long mincost(vector<long long> &pods, vector<long long> &cost) { 
    map<long long, multiset<long long>> mp; 

    long long n=pods.size();
    for(long long i=0;i<n;i++) { 
        mp[pods[i]].insert(cost[i]); 
    } 
     
    long long sum=0;
    long long res=0;
    long long curr=(*mp.begin()).first; 

    multiset<long long> st; 
     
    while(true){ 
        if(st.size()==0){ 
            if(mp.lower_bound(curr)==mp.end()) break; 
            curr=(*mp.lower_bound(curr)).first; 
        } 
 
        if(mp.find(curr)!=mp.end()){ 
            for(auto &x:mp[curr]){ 
                st.insert(x); 
                sum+=x; 
            } 
        } 
 
        auto it=st.end(); it--; 
        sum-=*it; 
        res+=sum; 
        st.erase(it); 
        curr++; 
    } 
 
    return res;
}