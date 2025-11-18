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
struct DNode{
    int data;
    DNode* prev;
    DNode* next;
};

DNode* insertFirstD(DNode* head,int x){
    DNode* t=new DNode{x,0,head};
    if(head) head->prev=t;
    return t;
}

DNode* insertLastD(DNode* head,int x){
    DNode* t=new DNode{x,0,0};
    if(!head) return t;
    DNode* p=head;
    while(p->next) p=p->next;
    p->next=t;
    t->prev=p;
    return head;
}

DNode* insertAfterD(DNode* head,int key,int x){
    DNode* p=head;
    while(p){
        if(p->data==key){
            DNode* t=new DNode{x,p,p->next};
            if(p->next) p->next->prev=t;
            p->next=t;
            return head;
        }
        p=p->next;
    }
    return head;
}

DNode* insertBeforeD(DNode* head,int key,int x){
    if(head->data==key) return insertFirstD(head,x);
    DNode* p=head;
    while(p){
        if(p->data==key){
            DNode* t=new DNode{x,p->prev,p};
            p->prev->next=t;
            p->prev=t;
            return head;
        }
        p=p->next;
    }
    return head;
}

DNode* deleteD(DNode* head,int key){
    if(!head) return head;
    DNode* p=head;
    while(p){
        if(p->data==key){
            if(p==head){
                head=head->next;
                if(head) head->prev=0;
                delete p;
                return head;
            }
            if(p->next) p->next->prev=p->prev;
            p->prev->next=p->next;
            delete p;
            return head;
        }
        p=p->next;
    }
    return head;
}

bool searchD(DNode* head,int x){
    while(head){
        if(head->data==x) return true;
        head=head->next;
    }
    return false;
}

int sizeD(DNode* head){
    int c=0;
    while(head){ c++; head=head->next; }
    return c;
}

