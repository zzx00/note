//链表

//链表是一种线性数据结构，数据结构中元素是一对一的关系
//比如：a->b->c->d
//表示a的直接后继是b，a是b的直接前驱

#include <iostream>

using namespace std;

struct node
{
    int num;
    node *next;
};//节点

node *head,*p;

//初始化链表
void init(){
    p=head=new node;
    p->next=NULL;
    p->num=0;
}

//在尾部添加一个数据
void add(int data){
    node *pn;
    if(head->num==0){
        p->num=data;
    }else{
        pn=new node;
        p->next=pn;
        p=pn;
        p->num=data;
        p->next=NULL;
    }
}

//输入链表长度
int length(){
    node *temp;
    temp=head;
    int leng=0;
    if(temp->next==NULL){
        return leng;
    }else{
        leng++;
        while(temp->next){
            leng++;
            temp=temp->next;
        }
    }
    return leng;
}

//整表创建
void create(int nums){
    node *temp;
    int leng=0;
    while(leng!=nums){
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
}


//在中间插入数据
void insert(int pos,int data){
    node *temp,*temp2;
    int leng=0;
    if(pos==0){
        temp=new node;
        temp->num=data;
        temp->next=head;
        head=temp;
    }else{
        temp=head;
        while(leng!=pos-1){
            if(temp->next==NULL&&leng!=pos-1){
                cout<<"超出长度"<<endl;
                return ;
            }
            temp=temp->next;
            leng++;
        }
        temp2=new node;
        temp2->num=data;
        temp2->next=temp->next;
        temp->next=temp2;
        return;
    }
}

//整表查询
void du(){
    node *temp;
    temp=head;
    while(temp->next!=NULL){
        cout<<temp->num<<' ';
        temp=temp->next;
    }
    cout<<temp->num<<endl;
}

//单个查询
void get_num(int pos){
    if(pos==0){
        cout<<head->num;
    }else{
        node *temp;
        temp=head;
        int leng=0;
        while(leng!=pos){
            if(leng!=pos&&temp->next==NULL){
                cout<<"超出链表长度"<<endl;
                return;
            }
            temp=temp->next;
            leng++;
        }
        cout<<temp->num<<endl;
    }
}

int main(){
    init();
    create(3);
    insert(2,5);
    cout<<length()<<endl;
    du();
    get_num(3);
    return 0;
}