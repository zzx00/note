#include <iostream>
#include <string>
using namespace std;

class Person{
public:
    int age;
    string name;
    Person(int a,string b){
        age=a;
        name=b;
    }
};

//对比两个数据是否相等函数
template<typename T>
bool cmp(T &a,T &b){
    if(a==b){
        return true;
    }
    return false;
}

//利用具体化Person的版本实现代码，具体化会优先调用
template<> bool cmp(Person &a,Person &b){
    if(a.age==b.age&&a.name==b.name){
        return true;
    }
    return false;
}

void test01(){
    int a=10,b=20;
    cout<<cmp(a,b)<<endl;
}

void test02(){
    Person p1(10,"Tom");
    Person p2(10,"Tom");
    cout<<cmp(p1,p2)<<endl;
}

int main(){
    test01();
    test02();
}