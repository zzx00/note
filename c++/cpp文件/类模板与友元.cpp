#include <iostream>
#include <string>

using namespace std;

template<class T1,class T2>
class Person;

template<class T1,class T2>
void printPerson(Person<T1,T2> p){
    cout<<p.m_Name<<' '<<p.m_Age<<endl;
}


template<class T1,class T2>
class Person{
    //全局函数类内实现
    // friend void printPerson(Person<T1,T2> p){
    //     cout<<p.m_Name<<' '<<p.m_Age<<endl;
    // }
    //全局函数类外实现
    //加空模板参数列表
    //如果全局函数类外实现，需要让编译器提前知道这个函数存在
    friend void printPerson<>(Person<T1,T2> p);
public:
    Person(T1 name,T2 age){
        this->m_Name=name;
        this->m_Age=age;
    }
private:
    T1 m_Name;
    T2 m_Age;
};

//通过全局函数打印Person的信息
void test01(){
    Person<string,int>p("Bella",18);
    printPerson(p);
    
}

// template<class T1,class T2>
// void printPerson(Person<T1,T2> p){
//     cout<<p.m_Name<<' '<<p.m_Age<<endl;
// }

int main(){
    test01();
}