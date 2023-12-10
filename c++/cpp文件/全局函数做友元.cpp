#include <iostream>
#include <string>
using namespace std;


//建筑物类
class Building
{
    //guimi函数是一个友元，可以访问类中私有成员
    friend void guimi(Building *building);
private:
    string m_bedroom;//卧室
public:
    Building();
    ~Building();
    string m_SittingRoom;// 客厅

};

Building::Building()
{
    m_SittingRoom="客厅";
    m_bedroom="卧室";
}

Building::~Building()
{
}


//全局函数，既能访问公共成员也能访问私有成员
void guimi(Building *building){
    cout<<"全局函数正在访问"<<building->m_SittingRoom<<endl;

    cout<<"全局函数正在访问"<<building->m_bedroom<<endl;
    return;
}


void test01(){
    Building building;
    guimi(&building);
}

int main(){
    test01();
}