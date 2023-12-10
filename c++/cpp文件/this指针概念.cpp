#include <iostream>

using namespace std;

class Person
{
private:
    /* data */
public:
    int age;
    Person(int age){//成员函数中会认为这三个age是一样的，和成员变量中的age没关系
        this->age=age;//加上this中会把这两个age看成一样的，this->age和成员变量中age一样
        //this指针指向的是被调用的成员函数所使用的对象
    }
    ~Person();
    Person& PersonAddPerson(Person &p){//记得加&，用引用的方式做一个返回
    //如果不加&的话认为调用了拷贝构造函数，出了一个副本
    //p2.PersonAddPerson(p1)成为p2',p2.PersonAddPerson(p1).PersonAddPerson(p1)成为p2''
    //p2.age是20，p2''.age是30，相当于p2'和p2''参与了后面的运算，而不是p2
        this->age+=p.age;
        //this指向的是一个p2的指针，*this指向的就是p2本体
        return *this;
    }
};


Person::~Person()
{
}
//解决名称冲突
void test01(){
    Person p1(18);
    cout<<p1.age<<endl;
    return ;
}


//返回对象本身用*this
void test02(){
    Person p1(10);
    Person p2(10);
    //链式编程思想
    p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
    //如果想多次调用的话p2.PersonAddPerson(p1).PersonAddPerson(p1);不行，因为返回值是void
    //但如果返回值是p2类型就可以
    cout<<p2.age<<endl;
}

int main(){
    test01();
    test02();
}