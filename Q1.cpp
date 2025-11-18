#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insertFirst(Node* head, int x) {
    Node* t=new Node{x,0};
    if(!head){ t->next=t; return t; }
    Node* p=head;
    while(p->next!=head) p=p->next;
    p->next=t;
    t->next=head;
    return t;
}

Node* insertLast(Node* head,int x){
    Node* t=new Node{x,0};
    if(!head){ t->next=t; return t; }
    Node* p=head;
    while(p->next!=head) p=p->next;
    p->next=t;
    t->next=head;
    return head;
}

Node* insertAfter(Node* head,int key,int x){
    if(!head) return head;
    Node* p=head;
    do{
        if(p->data==key){
            Node* t=new Node{x,p->next};
            p->next=t;
            return head;
        }
        p=p->next;
    }while(p!=head);
    return head;
}

Node* insertBefore(Node* head,int key,int x){
    if(!head) return head;
    if(head->data==key) return insertFirst(head,x);
    Node* p=head;
    do{
        if(p->next->data==key){
            Node* t=new Node{x,p->next};
            p->next=t;
            return head;
        }
        p=p->next;
    }while(p!=head);
    return head;
}

Node* del(Node* head,int key){
    if(!head) return head;
    Node* p=head;
    Node* q=0;
    do{
        if(p->data==key){
            if(p==head){
                if(head->next==head){ delete head; return 0; }
                Node* r=head;
                while(r->next!=head) r=r->next;
                head=head->next;
                r->next=head;
                delete p;
                return head;
            }
            q->next=p->next;
            delete p;
            return head;
        }
        q=p; p=p->next;
    }while(p!=head);
    return head;
}

bool search(Node* head,int x){
    if(!head) return false;
    Node* p=head;
    do{
        if(p->data==x) return true;
        p=p->next;
    }while(p!=head);
    return false;
}

void displayCircular(Node* head){
    if(!head) return;
    Node* p=head;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
    cout<<head->data<<" ";
}

int sizeCircular(Node* head){
    if(!head) return 0;
    int c=0;
    Node* p=head;
    do{
        c++; p=p->next;
    }while(p!=head);
    return c;
}
