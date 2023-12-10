#include <iostream>

using namespace std;

void swap1(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void swap2(int a,int b){
    int temp=a;
    a=b;
    b=temp;
}

void swap3(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int& test01(){
    int a=10;   //存放在栈区
    return a;
}

int& test02(){
    static int a=10;   //静态变量，存放在全局区，程序结束后系统释放
    return a;
}

int main(){
    // int a=10,b=20;
    // swap1(a,b);
    // cout<<a<<' '<<b<<endl;
    // swap2(a,b);
    // cout<<a<<' '<<b<<endl;
    // swap3(&a,&b);
    // cout<<a<<' '<<b<<endl;

    int& ref=test01();
    cout<<ref<<endl;
    cout<<ref<<endl;
    int& ref2=test02();
    cout<<ref2<<endl;		
    cout<<ref2<<endl;		//输出不会错误
    
    test02()=1000;
    cout<<ref2<<endl;		
    cout<<ref2<<endl;
    return 0;
}