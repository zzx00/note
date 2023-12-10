#include <iostream>
#include <string>
using namespace std;

//函数调用运算符重载

//打印输出类
class MyPrint
{
private:
    
public:
    MyPrint();
    ~MyPrint();
    //重载函数调用运算符
    void operator()(string test){
        cout<<test<<endl;
    }
};

MyPrint::MyPrint()
{
}

MyPrint::~MyPrint()
{
}

void myprint02(string test){
    cout<<test<<endl;
}

void test01(){
    MyPrint myprint;
    myprint("hello world");//重载()之后使用的，由于使用起来非常类似于函数调用，因此称为仿函数
    myprint02("hello world!");//函数调用
}


//仿函数非常灵活，没有固定的写法
//加法类
class MyAdd
{
private:
    /* data */
public:
    MyAdd();
    ~MyAdd();
    int operator()(int a,int b){
        return a+b;
    }
};

MyAdd::MyAdd()
{
}

MyAdd::~MyAdd()
{
}

void test02(){
    MyAdd myadd;
    int ret=myadd(100,100);
    cout<<"ret="<<ret<<endl;

    //匿名函数对象
    cout<<MyAdd()(100,100)<<endl;//创建一个匿名对象，当前运行完就被释放
}

int main(){
    test01();
    test02();
}