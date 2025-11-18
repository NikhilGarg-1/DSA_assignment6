#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
};

Node* insertLast(Node* head,char x){
    Node* t=new Node{x,0,0};
    if(!head) return t;
    Node* p=head;
    while(p->next) p=p->next;
    p->next=t;
    t->prev=p;
    return head;
}

bool isPalindrome(Node* head){
    if(!head) return true;
    Node* p=head;
    Node* q=head;
    while(q->next) q=q->next;
    while(p!=q && q->next!=p){
        if(p->data!=q->data) return false;
        p=p->next;
        q=q->prev;
    }
    return true;
}

int main(){
    Node* head=0;
    int n;
    char x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        head=insertLast(head,x);
    }
    if(isPalindrome(head)) cout<<"Palindrome";
    else cout<<"Not Palindrome";
}
