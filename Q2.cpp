#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insertLast(Node* head,int x){
    Node* t=new Node{x,0};
    if(!head){
        t->next=t;
        return t;
    }
    Node* p=head;
    while(p->next!=head) p=p->next;
    p->next=t;
    t->next=head;
    return head;
}

void display(Node* head){
    if(!head) return;
    Node* p=head;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
    cout<<head->data;
}

int main(){
    Node* head=0;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        head=insertLast(head,x);
    }
    display(head);
}
