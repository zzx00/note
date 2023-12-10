#include <iostream>

using namespace std;

class person
{
private:
    //可读可写
    string _name;

    //可读可写  若写范围为0~150
    int _age;
public:
    void setname(string name){
        _name=name;
    }
    string getname(){
        return _name;
    }
    int getage(){
        return _age;
    }
    void setage(int age){
        if(age>0&&age<150){
            _age=age;
        }else{
            _age=0;
            cout<<"error"<<endl;
            return;
        }
    }
};

int main(){
    person p1;
    p1.setname("aaa");
    cout<<p1.getname()<<endl;
    p1.setage(3000);
    p1.setage(20);
    cout<<p1.getage()<<endl;
}