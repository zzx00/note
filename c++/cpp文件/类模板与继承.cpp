#include <iostream>
#include <typeinfo>
using namespace std;

template<class T>
class Base{
public:
    T m;
};

//class Son:public Base{//错误，必须要知道父类中的T的类型，才能继承给子类
class Son:public Base<int>{

};


//如果想灵活指定父类中T的类型，子类也需要变类模板
template<class T1,class T2>
class Son2:public Base<T2>{
public:
    T1 obj;
    Son2(){
        cout<<typeid(T1).name()<<endl<<typeid(T2).name()<<endl;
    }
};

void test02(){
    Son2<int,char>S2;
}

void test01(){
    Son s1;
}

int main(){
    test01();
    test02();
}