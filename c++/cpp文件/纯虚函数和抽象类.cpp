#include <iostream>
using namespace std;

class Base{
public:
//纯虚函数
//只要有一个纯虚函数，这个类被称为抽象类，无法实例化对象,抽象类的子类必须重写父类中的虚函数，不然也属于抽象类
    virtual void func()=0;
};

class Son:public Base{
public:
    void func(){
        cout<<"func函数调用"<<endl;
    }
};

void test01(){
    //多态  父类的指针或引用指向子类对象
    Base *base=new Son;
    base->func();
}

int main(){
    test01();
}