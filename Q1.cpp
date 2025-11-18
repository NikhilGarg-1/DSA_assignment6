#include <iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
};

CNode* insertFirstC(CNode* head,int x){
    CNode* t=new CNode{x,0};
    if(!head){ t->next=t; return t; }
    CNode* p=head;
    while(p->next!=head) p=p->next;
    p->next=t;
    t->next=head;
    return t;
}

CNode* insertLastC(CNode* head,int x){
    CNode* t=new CNode{x,0};
    if(!head){ t->next=t; return t; }
    CNode* p=head;
    while(p->next!=head) p=p->next;
    p->next=t;
    t->next=head;
    return head;
}

CNode* insertAfterC(CNode* head,int key,int x){
    if(!head) return head;
    CNode* p=head;
    do{
        if(p->data==key){
            CNode* t=new CNode{x,p->next};
            p->next=t;
            return head;
        }
        p=p->next;
    }while(p!=head);
    return head;
}

CNode* insertBeforeC(CNode* head,int key,int x){
    if(!head) return head;
    if(head->data==key) return insertFirstC(head,x);
    CNode* p=head;
    do{
        if(p->next->data==key){
            CNode* t=new CNode{x,p->next};
            p->next=t;
            return head;
        }
        p=p->next;
    }while(p!=head);
    return head;
}

CNode* deleteC(CNode* head,int key){
    if(!head) return head;
    CNode* p=head;
    CNode* q=0;
    do{
        if(p->data==key){
            if(p==head){
                if(head->next==head){ delete head; return 0; }
                CNode* r=head;
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

bool searchC(CNode* head,int x){
    if(!head) return false;
    CNode* p=head;
    do{
        if(p->data==x) return true;
        p=p->next;
    }while(p!=head);
    return false;
}

struct DNode {
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
    if(!head) return head;
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

int main(){
    CNode* chead=0;
    DNode* dhead=0;
    int ch,x,key;

    while(true){
        cin>>ch;
        if(ch==0) break;

        if(ch==1){ cin>>x; chead=insertFirstC(chead,x); }
        if(ch==2){ cin>>x; chead=insertLastC(chead,x); }
        if(ch==3){ cin>>key>>x; chead=insertAfterC(chead,key,x); }
        if(ch==4){ cin>>key>>x; chead=insertBeforeC(chead,key,x); }
        if(ch==5){ cin>>key; chead=deleteC(chead,key); }
        if(ch==6){ cin>>x; cout<<searchC(chead,x)<<endl; }

        if(ch==7){ cin>>x; dhead=insertFirstD(dhead,x); }
        if(ch==8){ cin>>x; dhead=insertLastD(dhead,x); }
        if(ch==9){ cin>>key>>x; dhead=insertAfterD(dhead,key,x); }
        if(ch==10){ cin>>key>>x; dhead=insertBeforeD(dhead,key,x); }
        if(ch==11){ cin>>key; dhead=deleteD(dhead,key); }
        if(ch==12){ cin>>x; cout<<searchD(dhead,x)<<endl; }
    }
}


