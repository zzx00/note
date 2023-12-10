#include <iostream>
#include <string>
using namespace std;

class Building;
class GuiMi
{
private:
public:
    GuiMi();
    ~GuiMi();
    Building *building;
    void visit();//让visit可以访问Building中私有成员
    void visit2();//让visit2不可以访问Building中私有成员
};


class Building
{
    friend void GuiMi::visit();//告诉编译器这个GuiMi类下的visit函数作为本类的友元，可以访问私有成员
private:
    string m_BedRoom;//卧室
public:
    Building();
    ~Building();
    string m_SittingRoom;//客厅
};

Building::Building()
{
    m_SittingRoom="客厅";
    m_BedRoom="卧室";
}

Building::~Building()
{
}

GuiMi::GuiMi()
{
    building=new Building;
}

GuiMi::~GuiMi()
{
}

void GuiMi::visit(){
    cout<<"visit函数正在访问"<<building->m_SittingRoom<<endl;
    cout<<"visit函数正在访问"<<building->m_BedRoom<<endl;
}

void GuiMi::visit2(){
    cout<<"visit2函数正在访问"<<building->m_SittingRoom<<endl;
    //cout<<"visit2函数正在访问"<<building->m_BedRoom<<endl;
}

void test01(){
    GuiMi gg;
    gg.visit();
    gg.visit2();
}

int main(){
    test01();
}