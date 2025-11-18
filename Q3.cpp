#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

struct CNode {
    int data;
    CNode* next;
};

DNode* insertLastD(DNode* head,int x){
    DNode* t=new DNode{x,0,0};
    if(!head) return t;
    DNode* p=head;
    while(p->next) p=p->next;
    p->next=t;
    t->prev=p;
    return head;
}

CNode* insertLastC(CNode* head,int x){
    CNode* t=new CNode{x,0};
    if(!head){
        t->next=t;
        return t;
    }
    CNode* p=head;
    while(p->next!=head) p=p->next;
    p->next=t;
    t->next=head;
    return head;
}

int sizeD(DNode* head){
    int c=0;
    while(head){
        c++;
        head=head->next;
    }
    return c;
}

int sizeC(CNode* head){
    if(!head) return 0;
    int c=0;
    CNode* p=head;
    do{
        c++;
        p=p->next;
    }while(p!=head);
    return c;
}

int main(){
    DNode* dhead=0;
    CNode* chead=0;

    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        dhead=insertLastD(dhead,x);
    }

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        chead=insertLastC(chead,x);
    }

    cout<<sizeD(dhead)<<endl;
    cout<<sizeC(chead)<<endl;
}
