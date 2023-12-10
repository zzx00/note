#include <iostream>

using namespace std;

class student
{
private:
    string s_name;
    int s_age;
public:
    void showname(){
        cout<<s_name<<endl;
    }
    void showage(){
        cout<<s_age<<endl;
    }
    void getname(string name){
        s_name=name;
    }
    void getage(int age){
        s_age=age;
    }
    
};


int main(){
    student stu1;
    stu1.getage(20);
    stu1.getname((string)"aaa");
    stu1.showage();
    stu1.showname();
}