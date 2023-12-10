#include <iostream>
using namespace std;

typedef struct node
{
    int num;
    struct node* lchild;
    struct node* rchild;
}node,*btnode;

void create(btnode *s){
    int num1;
    cin>>num1;
    if(num1==0){
        (*s)=NULL;
    }else{
    	(*s)=new node;
        (*s)->num=num1;
        create(&((*s)->lchild));
        create(&((*s)->rchild));
    }
    return ;
}

void xian(btnode s){
    if(s==NULL){
        return;
    }else{
        cout<<s->num;
        xian(s->lchild);
        xian(s->rchild);
    }
    return;
}


void zhong(btnode s){
    if(s==NULL){
        return;
    }else{
        
        zhong(s->lchild);
        cout<<s->num;
        zhong(s->rchild);
    }
    return;
}


void hou(btnode s){
    if(s==NULL){
        return;
    }else{
        hou(s->lchild);
        hou(s->rchild);
        cout<<s->num;
    }
}


int shen(btnode s){
    if(s==NULL){
        return 0;
    }else{
        int left,right,depth=0;
        left=shen(s->lchild);
        right=shen(s->rchild);
        depth=left>right?left+1:right+1;
        return depth;
    }
}


int main(){
    printf("请输入结点的信息\n");
    btnode s;
    create(&s);
    printf("二叉树的先序遍历是：");
    xian(s);
    cout<<endl;
    printf("二叉树的中序遍历是：");
    zhong(s);
    cout<<endl;
    printf("二叉树的后序遍历是：");
    hou(s);
    cout<<endl;
    printf("二叉树的深度是：");
    printf("%d\n",shen(s));
    return 0;
}

//1 2 3 0 0 5 0 0 6 7 0 0 8 0 0
