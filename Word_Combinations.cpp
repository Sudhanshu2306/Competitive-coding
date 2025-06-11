#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    vector<Node*> child;
    bool flag;  

    Node(){
        child.resize(26,nullptr);
        this->flag=false;
    }
};
class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(string s){
        Node* temp=root;
        for(auto it:s){
            int x=it-'a';
            if(temp->child[x]==nullptr) temp->child[x]=new Node();
            temp=temp->child[x];
        }
        temp->flag=true;
    }
    bool search(string s){
        Node* temp=root;
        for(auto it:s){
            int x=it-'a';
            if(temp->child[x]==nullptr) return false;
            temp=temp->child[x];
        }
        return temp->flag;
    }
};
int main(){
    string s; cin>>s;
    int n=s.size();
    int k; cin>>k;
    vector<string> a(k);
    for(int i=0;i<k;i++) cin>>a[i];

    Trie t;
    for(auto it:a) t.insert(it);
    int mod=1e9+7;
    vector<int> dp(n+1);
    dp[n]=1;
    for(int i=n-1;i>=0;i--){
        Node* node=t.root;
        for(int j=i;j<n;j++) {
            int c=s[j]-'a';
            if(node->child[c]==nullptr) break;    
            node=node->child[c];
            if(node->flag){
                dp[i]=(dp[i]+dp[j+1])%mod;
            }
        }
    }
    cout<<dp[0]<<endl;

    return 0;
}