#include <iostream>
using namespace std;

//普通函数与函数模板调用规则
void myPrint(int a,int b){
    cout<<"PuTong"<<endl;
}

template<typename T>
void myPrint(T a,T b){
    cout<<"MuBan"<<endl;
}

template<typename T>
void myPrint(T a,T b,T c){
    cout<<"ChongZaiMuBan"<<endl;
}

void test01(){
    int a=10;
    int b=20;
    myPrint(a,b);

    //通过空模板的参数列表，强制调用函数模板
    myPrint<>(a,b,100);

    //如果函数模板产生更好的匹配，优先函数模板
    char c1='a';
    char c2='c';
    myPrint(c1,c2);
}

int main(){
    test01();
}