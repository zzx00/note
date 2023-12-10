#include <iostream>
using namespace std;

//成员变量和成员函数是分开存储的
class Person
{
private:
    
public:
    //只有非静态成员变量属于类的对象
    int m_A;//非静态成员变量
    static int m_B;//静态成员变量不属于类的对象上，所以类内占用空间不变
    void func(){}   //非静态成员函数，不属于类的对象
    static void func2(){} //静态成员函数也只有一份，不属于类的对象上

    Person(/* args */);
    ~Person();
};

//类内声明类外初始化
int Person::m_B=0;

Person::Person(/* args */)
{
}

Person::~Person()
{
}

void test01(){
    Person p;
    //空对象占用的内存空间是1个字节
    //c++编译器会为每个空对象也分配一个字节空间，是为了区分空对象所占内存的位置
    //每个空对象也应该有一个独一无二的内存地址
    cout<<sizeof(p)<<endl;
}

void test02(){
    Person p;
    //不是空的就按实际大小占用内存
    cout<<sizeof(p)<<endl;
}

int main(){
    //test01();
    test02();
    return 0;
}