#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    Node* next;
    int data;
    
    Node(int data){
        this->next=nullptr;
        this->data=data;
    }
};

Node* deleteHead(Node* head){
    if(head==nullptr) return head;
    
    Node* temp=head;
    head=head->next;
    delete temp;
    
    return head;
}

Node* deleteTail(Node* head){
    if(head==nullptr) return nullptr;
    if(head->next==nullptr){
        delete head;
        return nullptr;
    } 
    Node* temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    Node* x=temp->next;
    temp->next=nullptr;
    delete x;
    
    return head;
}

Node* deleteKth(Node* head, int k){
    Node* temp=head;
    Node* prev=nullptr;
    int count=0;
    if(k==1){
        head=head->next;
        return head;
    }
    while(temp!=nullptr){
        count++;
        if(count==k){
            prev->next=prev->next->next;
            temp->next=nullptr;
            delete temp; break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

void print(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    int n; cin>>n;
    Node* head=new Node(-1);
    Node* temp=head;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        temp->next=new Node(x);
        temp=temp->next;
    }
    head=head->next;
    
    // Node* x=deleteHead(head);
    // print(x);
    // Node* y=deleteTail(head);
    // print(y);

    Node* z=deleteKth(head,2);
    print(z);
    return 0;
}