#include <iostream>
#include <cstring>
using namespace std;

char small[10009],big[100009];         //模式串和文本串
int check[10009];                       //next数组
int a,b;                                //a是模式串长度，b是文本串长度

void get_next(){
    int k=-1,j=0;                       //j是当前模式串next进行的位数
    check[0]=-1;
    while(j<a){
        if(k==-1||small[k]==small[j]){
            check[++j]=++k;
        }else{
            k=check[k];                 //回溯，不能直接写等于-1，不断向前回跳，直到可以继续匹配，可能有嵌套
        }
    }
}

void kmp(){
    int i=0,j=0;
    while(i<b){
        if(j==-1||small[j]==big[i]){
            i++;
            j++;                    //如果匹配，全往后移动一位
        }else{
            j=check[j];             //不符合，主串不用动，子串回溯
        }
        if(j==a){
            cout<<i-a<<endl;
            j=check[j];
        }
    }
}

int main(){
    cin>>big;
    cin>>small;
    a=strlen(small);
    b=strlen(big);
    cout<<a<<' '<<b<<endl;
    get_next();
    for(int i=1;i<=a;i++){
        cout<<check[i]<<' ';
    }
    cout<<endl;
    kmp();
    return 0;
}
