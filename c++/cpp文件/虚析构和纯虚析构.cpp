#include <iostream>
#include <string>
using namespace std;

//虚析构和纯虚析构
class Animal{
public:
//纯虚函数
    Animal(){
        cout<<"animal构造函数调用"<<endl;
    }
//    virtual ~Animal(){
// 利用虚析构可以解决父类指针释放子类对象不干净的问题
//        cout<<"animal析构函数调用"<<endl;
//    }
    //纯虚析构 也能解决释放的问题，但是需要声明也需要实现
    //有了纯虚析构之后，这个类也属于抽象类，不能实例化对象
    virtual ~Animal()=0;
    virtual void speak()=0;
};

Animal:: ~Animal(){
    cout<<"animal纯析构函数调用"<<endl;
}

class Cat:public Animal{
public:
    Cat(string name){
        cout<<"cat构造函数调用"<<endl;
        m_Name = new string(name);
    }
    void speak(){
        cout<<*m_Name<<"小猫在说话"<<endl;
    }
    ~Cat(){
        if(m_Name!=NULL){
            cout<<"cat析构函数调用"<<endl;
            delete m_Name;
            m_Name=NULL;
        }
    }
    string *m_Name;
};

void test01(){
    Animal * animal=new Cat("Tom");
    animal->speak();
    //父类指针在析构的时候哦不会调用子类中析构函数，导致子类如果有堆区数据，会出现内存泄漏
    delete animal;
}

int main(){
    test01();
}