#include <iostream>
using namespace std;

//空指针调用成员函数
class Person
{
private:
public:
    int m_Age;
    void ShowPersonAge(){
        if(this==NULL){//加上这一行可避免代码崩，提高健壮性
            return;
        }
        //报错原因是传入的指针为空。访问空指针里的属性会报错
        cout<<m_Age<<endl;
    }
    void ShowClassName(){
        cout<<"this is Person class!"<<endl;
    }
    Person(/* args */);
    ~Person();
};

Person::Person(/* args */)
{
}

Person::~Person()
{
}

void test01(){
    Person *p=NULL;
    //调用第一个没有出错
    p->ShowClassName();
    //报错原因是传入的指针为空。访问空指针里的属性会报错
    p->ShowPersonAge();
}


int main(){
    test01();
}