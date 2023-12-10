#include <iostream>

using namespace std;

//继承中同名成员处理方式
class Base{
public:
    Base(){
        m_A=100;
    }
    void func(){
        cout<<"Base作用域下func函数调用"<<endl;
    }
    void func(int a){
        cout<<"Base作用域下func(int a)函数调用"<<endl;
    }
    int m_A;
};

class Son:public Base{
public:
    Son(){
        m_A=200;
    }
    void func(){
        cout<<"Son作用域下func函数调用"<<endl;
    }
    int m_A;
};

void test01(){
    Son s1;
    cout<<"m_A="<<s1.m_A<<endl;//如果直接输出默认为子类的数据
    cout<<"Base中m_A="<<s1.Base::m_A<<endl;//使用这样的方式就能访问到父类中数据，需要加作用域
}

//同名成员函数处理
void test02(){
    Son s2;
    s2.func();//直接调用调用的是子类的函数
    s2.Base::func();
    //如果子类中出现与父类同名的成员函数，子类的同名成员会隐藏掉父类中所有的同名成员函数
    //如果想访问到父类中被隐藏的同名成员函数，需要加作用域
    s2.Base::func(100);
}

int main(){
    test01();
    test02();
}