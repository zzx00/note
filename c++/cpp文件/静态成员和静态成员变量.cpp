#include <iostream>
using namespace std;

class Person
{
private:
    static int m_b;
public:
    static int m_a;
    //所有对象共享同一份数据
    //编译阶段就分配内存
    //类内声明，类外初始化
};

void test(){
    Person p;
    cout<<p.m_a<<endl;
    //修改，数据共享
    Person p2;
    p2.m_a=200;
    cout<<p2.m_a<<endl;
}

int Person::m_a=100;
int Person::m_b=200;
void test2(){
    //静态成员变量，不属于某个对象上，所有对象共享同一份数据

    //两种访问方式
    //1、通过对象访问
    Person p;
    cout<<p.m_a<<endl;
    //2、通过类名进行访问
    cout<<Person::m_a<<endl;

    //cout<<Person::m_b<<endl;  访问不到私有的
}

int main(){

    test();
    test2();
}