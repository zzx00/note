#include <iostream>

using namespace std;

//继承中的同名静态成员处理方式
class Base{
public:
    static int m_A;
    static void func(){
        cout<<"Base-static func()"<<endl;
    }
    static void func(int a){
        cout<<"Base-static func(int a)"<<endl;
    }
};

int Base::m_A=100;

class Son:public Base{
public:
    static int m_A;
    static void func(){
        cout<<"Son-static func()"<<endl;
    }
};

int Son::m_A=200;

//同名静态成员属性
void test01(){
    //1.通过对象访问
    cout<<"通过对象访问"<<endl;
    Son s1;
    cout<<"Son 下s1.m_A="<<s1.m_A<<endl;
    cout<<"Base 下s1.m_A="<<s1.Base::m_A<<endl;
    //2.通过类名访问
    cout<<"通过类名访问"<<endl;
    cout<<"Son 下s1.m_A="<<Son::m_A<<endl;
    cout<<"Base 下s1.m_A="<<Base::m_A<<endl;
    //第一个::表示通过类名方式访问，第二个::表示访问父类作用域下
    cout<<"Base 下s1.m_A="<<Son::Base::m_A<<endl;
}


//同名静态成员函数
void test02(){
    Son s2;
    //通过对象访问
    s2.func();
    s2.Base::func();
    s2.Base::func(100);
    //通过类名访问
    Son::func();
    Son::Base::func();
    //当子类和父类拥有同名静态成员函数时，子类会隐藏父类中同名成员函数，加作用域可以访问到父类中同名成员函数
    Son::Base::func(100);
}

int main(){
    test01();
    test02();
}