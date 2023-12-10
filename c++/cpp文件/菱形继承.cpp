#include <iostream>
using namespace std;


class Animal{
public:
    int m_Age;
};
//利用虚继承可以解决菱形继承问题

//继承之前，加上关键字virtual变为虚继承
//Animal类称为虚基类
//
class Sheep:virtual public Animal{};



class Camel:virtual public Animal{};

class YangTuo:public Sheep,public Camel{};

void test01(){
    YangTuo yt;
    //yt.m_Age=18;会报错，不明确
    yt.Sheep::m_Age=18;
    yt.Camel::m_Age=28;
    //当出现菱形继承的时候，两个父类拥有相同数据需要加作用域
    cout<<"yt.Sheep::m_Age="<<yt.Sheep::m_Age<<endl;
    cout<<"yt.Camel::m_Age="<<yt.Camel::m_Age<<endl;
    //菱形继承导致数据有两份，资源浪费
    //使用虚继承后可以用下面这种方式访问
    cout<<"yt.m_Age"<<yt.m_Age<<endl;

}

int main(){
    test01();
}