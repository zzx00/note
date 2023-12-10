#include <iostream>
#include <string>
using namespace std;

template<class T1,class T2>
class Person{
public:
    T1 m_Name;
    T2 m_Age;
    Person(T1 name,T2 age);
    void showPerson();

};

//构造函数类外实现
template<class T1,class T2>
Person<T1,T2>::Person(T1 name,T2 age){
    m_Name=name;
    m_Age=age;
}

//成员函数类外实现
template<class T1,class T2>
void Person<T1,T2>::showPerson(){
    cout<<m_Name<<' '<<m_Age<<endl;
}

void test01(){
    Person<string,int>p("Bella",18);
    p.showPerson();
}

int main(){
    test01();
}