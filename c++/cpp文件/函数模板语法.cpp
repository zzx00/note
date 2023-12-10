#include <iostream>
using namespace std;

//函数模板

//两个整型交换
void SwapInt(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

//交换两个浮点型
void SwapDouble(double &a,double &b){
    double temp=a;
    a=b;
    b=temp;
}

template <typename T>//声明一个模板，告诉编译器后面代码中紧跟的T不要报错，T是一个通用数据类型
void mySwap(T &a,T &b){
    T temp=a;
    a=b;
    b=temp;
}

void test01(){
    int a=10;
    int b=20;
    // SwapInt(a,b);
    //利用函数模板进行交换
    //两种方式使用函数模板
    //1、自动类型推导
    mySwap(a,b);
    //2、显式指定类型
    mySwap<int>(a,b);
    cout<<a<<' '<<b<<endl;
}

int main(){
    test01(); 
}