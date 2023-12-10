#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int maxn=500000;
const int maxw=20;
//利用数组来模拟链式存储
struct node
{
    int child[26];
    bool isword;
    int cnt;            //单词出现次数
    int acnt;           //前缀出现次数
    node(){
        isword=false;
        memset(child,0,sizeof(child));
        cnt=0;
        acnt=0;
    }
}T[maxn];

int sz=1;       //目前结点数

void insert(char s[]){
    int len=strlen(s);
    int u=0;
    for(int i=0;i<len;i++){
        int id=s[i]-'a';
        if(T[u].child[id]==0){
            T[u].child[id]=sz++;
        }
        u=T[u].child[id];
        T[u].cnt++;
    }
    T[u].isword=1;
    T[u].acnt++;
}

int findword(char s[]){
    int len=strlen(s);
    int u=0;
    for(int i=0;i<len;i++){
        int id=s[i]-'a';
        if(T[u].child==0){
            return 0;
        }
        u=T[u].child[id];
    }
    if(T[u].isword==1){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    char word1[maxw][maxw],word2[maxw][maxw];
    int num1,num2;
    cin>>num1>>num2;
    for(int i=0;i<num1;i++){
        cin>>word1[i];
        insert(word1[i]);
    }
    for(int i=0;i<num2;i++){
        cin>>word2[i];
        cout<<findword(word2[i])<<endl;
    }
}
//如果想要某个字符串为前缀的数量，将findword中的返回值变成cnt即可