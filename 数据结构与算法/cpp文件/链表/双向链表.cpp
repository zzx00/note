#include <iostream>
using namespace std;



struct node{
    int num;
    node *pre;
    node *next;
};

node *head,*t;

void create(){
    int cycle=1;
    node *temp=NULL;
    head=new node;
    t=head;
    while(cycle){
        int x;
        cout<<"请输入值x"<<endl;
        cin>>x;
        if(x!=0){
            temp=new node;
            temp->num=x;
            t->next=temp;
            temp->pre=t;
            t=temp;
        }else{
            cycle=0;
        }
    }
    head=head->next;
    head->pre=NULL;
    t->next=NULL;
}

//打印链表并计算长度
int length(){
    int n=0;
    node *temp;
    temp=head;
    while(temp!=NULL){
        n++;
        cout<<temp->num<<' ';
        temp=temp->next;
    }
    cout<<endl;
    return n;
}


void insert(int pos,int data){
    int now=0;
    node *temp=head;
    if(pos==0){
        node *t=new node;
        t->num=data;
        t->next=head;
        head->pre=t;
        head=t;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
        now++;
        if(now==pos-1&&temp->next!=NULL){
            node *pn=new node;
            pn->num=data;
            pn->next=temp->next;
            pn->pre=temp;
            temp->next=pn;
            return;
        }else if(now==pos-1&&temp->next==NULL){
            node *pn=new node;
            pn->num=data;
            pn->next=NULL;
            pn->pre=temp;
            temp->next=pn;
            return;
        }
    }
    cout<<"超出长度"<<endl;
    return;
}

void deletenode(int pos){
    int now=0;
    node *temp=head;
    if(pos==0){
        head=head->next;
        temp->next->pre=NULL;
        temp->next=NULL;
        delete temp;
        return;
    }else{
        while(temp->next!=NULL){
            temp=temp->next;
            now++;
            if(now==pos&&temp->next!=NULL){
                temp->pre->next=temp->next;
                temp->next->pre=temp->pre;
                delete temp;
                return;
            }else if(now==pos&&temp->next==NULL){
                temp->pre->next=NULL;
                delete temp;
                return;
            }
        }
        cout<<"删除位置超出长度"<<endl;
    }
}


int main(){
    create();
    insert(2,9);
    deletenode(0);
    cout<<length()<<endl;
    return 0;
}