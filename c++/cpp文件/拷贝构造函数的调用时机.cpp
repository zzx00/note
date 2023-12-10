#include <iostream>
using namespace std;

class Person
{
private:
    /* data */
public:
    int m_age; 
    Person(){
        cout<<"调用默认构造函数"<<endl;
    }
    Person(int age){
        m_age=age;
        cout<<"调用有参构造函数"<<endl;
    }
    Person(const Person &p){
        m_age=p.m_age;
        cout<<"调用拷贝构造函数"<<endl;
    }
    ~Person(){
        cout<<"调用析构函数"<<endl;
    }
};

void test(Person p){
}

Person test2(){
    Person p1;
    cout<<(int *)&p1<<endl;
    return p1;
}

int main(){
    Person p1=20;
    Person p2(p1);
    cout<<p2.m_age<<endl;
    test(p1);               //调用拷贝构造函数进行值传递，如果不写系统也有拷贝构造函数
    Person p3=test2();      //没有拷贝构造可能用了release模式，相当于局部变量没有销毁，正常应该会调用拷贝构造函数
    cout<<(int *)&p3<<endl;
}