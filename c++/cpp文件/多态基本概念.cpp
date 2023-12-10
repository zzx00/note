#include <iostream>
using namespace std;

//多态

//动态多态满足条件：1、有继承关系 2、子类要重写父类的虚函数，子类可写virtual也可不写
//重写：函数返回值类型、函数名、参数列表完全相同

//动态多态使用：父类的指针或者引用 执行子类对象
class Animal{
public:
//虚函数
    virtual void speak(){
        cout<<"动物在说话"<<endl;
    }
};

class Cat:public Animal{
public:
    void speak(){
        cout<<"小猫在说话"<<endl;
    }
};

//执行说话的函数
//地址早绑定，在编译阶段就确定了函数的地址
//如果想执行让猫说话，那么这个函数的地址就不能提前绑定，需要在运行阶段绑定，地址晚绑定
void doSpeak(Animal &ani){//Animal &ani=cat;  父子之间可以直接进行类型转换
    ani.speak();//根据传入对象不同确定说话的人不同，地址晚绑定
}

void test01(){
    Cat cat;
    doSpeak(cat);//父类引用指向子类对象
}

int main(){
    test01();
}