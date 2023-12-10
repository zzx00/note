#include <iostream>

using namespace std;

class Person
{
private:
    /* data */
public:
    Person(string name,int age);
    ~Person();
    string m_Name;
    int m_Age;
    //重载关系运算符==
    bool operator==(Person &p){//!=重载也一样
        if(this->m_Name==p.m_Name&&this->m_Age==p.m_Age){
            return true;
        }else{
            return false;
        }
    }
    bool operator!=(Person &p){
        if(this->m_Name==p.m_Name&&this->m_Age==p.m_Age){
            return false;
        }else{
            return true;
        }
    }
};

Person::Person(string name,int age)
{
    m_Name=name;
    m_Age=age;
}

Person::~Person()
{
}

void test01(){
    Person p1("Bella",18);
    Person p2("Diana",18);
    if(p1!=p2){
        cout<<"p1和p2是不相等的！"<<endl;
    }else{
        cout<<"p1和p2是相等的！"<<endl;
    }
}

int main(){
    test01();
}