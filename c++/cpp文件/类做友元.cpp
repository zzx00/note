#include <iostream>
#include <string>
using namespace std;


//类做友元
class Building;
class GuiMi
{
private:
public:
    void visit();//参观函数，访问Building中的属性
    GuiMi();
    ~GuiMi();
    Building *building;
};

class Building
{
private:
    string m_bedroom;//卧室
public:
    //让GuiMi类作为友元，可以访问本类中的私有成员
    friend class GuiMi;
    Building();
    ~Building();
    string m_sittingroom;//客厅
};

GuiMi::GuiMi()
{
    building=new Building;
}

GuiMi::~GuiMi()
{
}

void GuiMi::visit(){
    cout<<"GuiMi类正在访问"<<building->m_sittingroom<<endl;
    cout<<"GuiMi类正在访问"<<building->m_bedroom<<endl;
}



Building::Building()
{
    m_sittingroom="客厅";
    m_bedroom="卧室";
}

Building::~Building()
{
}


void test01(){
    GuiMi gg;
    gg.visit();
}


int main(){
    test01();
}