#include <iostream>
using namespace std;

struct node
{
    int num;
    node *lchild;
    node *rchild;
};
typedef node *bittree;

void insert(bittree *t,int num){
    if((*t)==NULL){
        (*t)=new node;
        (*t)->num=num;
        (*t)->lchild=NULL;
        (*t)->rchild=NULL;
    }
    if((*t)->num==num){
        return;
    }else if(num>(*t)->num){
        insert(&((*t)->rchild),num);
    }else{
        insert(&((*t)->lchild),num);
    }
}

int cha(bittree t,int num){
    if(t==NULL){
        cout<<"树中没有这个元素"<<endl;
        return 0;
    }else{
        if(num>t->num){
            cha(t->rchild,num);
        }else if(num==t->num){
            cout<<"树中存在这个数"<<endl;
            return 1;
        }else{
            cha(t->lchild,num);
        }
    }
}


void zhong(bittree t){
    if(t){
        zhong(t->lchild);
        cout<<t->num<<' ';
        zhong(t->rchild);
    }
}

int main(){
    bittree t;
    t=NULL;
    int a[10]={5,3,9,1,23,87,45,76,120,999};
    for(int i=0;i<10;i++){
        insert(&t,a[i]);
    }
    zhong(t);
    cout<<endl;
    cha(t,9);
    return 0;
}