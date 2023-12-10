#include <iostream>
using namespace std;
struct node{
    int num;
    node *next;
};

node *head,*p;

void init(){
    p=head=new node;
    p->next=NULL;
    p->num=0;
}

void create(int num){
    node *temp;
    int leng=0;
    while(leng!=num){
        if(head->num==0){
            head->num=++leng;
        }else{
            temp=new node;
            temp->num=++leng;
            p->next=temp;
            p=temp;
            p->next=NULL;
        }
    }
    p->next=head;
}

int main(){
    return 0;
}