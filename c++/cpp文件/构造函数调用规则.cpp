#include <iostream>
using namespace std;

class Person{
private:
    
public:
int m_age;
    Person(){
        cout<<"默认构造函数"<<endl;
    }
    Person(int a){
        m_age=a;
        cout<<"有参构造函数调用"<<endl;
    }
    Person(const Person &p){
        m_age=p.m_age;
        cout<<"调用拷贝构造函数"<<endl;
    }
    ~Person(){
        cout<<"析构函数调用"<<endl;
    }
};

void test(){
    Person p=18;
    Person p2=p;
    cout<<p2.m_age<<endl;
}

int main(){
    test();
}