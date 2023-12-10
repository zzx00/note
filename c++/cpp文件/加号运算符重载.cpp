#include <iostream>
using namespace std;

//加号运算符重载
//1、成员函数重载+号

class Person
{
private:
    
public:
    Person();
    ~Person();
    int m_A;
    int m_B;
    Person operator+(Person &p){
        Person temp;
        temp.m_A=this->m_A+p.m_A;
        temp.m_B=this->m_B+p.m_B;
        return temp;
    }
};

Person::Person()
{
}

Person::~Person()
{
}


//函数重载版本
Person operator+(Person &p,int num){
    Person temp;
    temp.m_A=p.m_A+num;
    temp.m_B=p.m_B+num;
    return temp;
}

void test01(){
    Person p1;
    p1.m_A=10;
    p1.m_B=10;
    Person p2;
    p2.m_A=10;
    p2.m_B=10;
    //成员函数重载的本质调用Person p3=p1.operator+(p2);简化为下面类型
    //全局函数重载的本质调用Person p3=operator+(p1,p2);简化为下面类型
    Person p3=p1+p2;
    //运算符重载也可以发生函数重载
    Person p4=p1+10;//Person类型+int类型
    cout<<"p3的m_A值为"<<p3.m_A<<endl;
    cout<<"p3的m_B值为"<<p3.m_B<<endl;
    cout<<"p4的m_A值为"<<p4.m_A<<endl;
    cout<<"p4的m_B值为"<<p4.m_B<<endl;
}


//2、全局函数重载+号
Person operator+(Person &p1,Person &p2){
    Person temp;
    temp.m_A=p1.m_A+p2.m_A;
    temp.m_B=p1.m_B+p2.m_B;
    return temp;
}


int main(){
    test01();
}