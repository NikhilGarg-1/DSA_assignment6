#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insertLast(Node* head,int x){
    Node* t=new Node{x,0};
    if(!head) return t;
    Node* p=head;
    while(p->next) p=p->next;
    p->next=t;
    return head;
}

bool isCircular(Node* head){
    if(!head) return false;
    Node* p=head->next;
    while(p && p!=head) p=p->next;
    return p==head;
}

int main(){
    Node* head=0;
    int n,x;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        head=insertLast(head,x);
    }

    int makeCircular;
    cin>>makeCircular;

    if(makeCircular){
        Node* p=head;
        while(p->next) p=p->next;
        p->next=head;
    }

    if(isCircular(head)) cout<<"Circular";
    else cout<<"Not Circular";
}
