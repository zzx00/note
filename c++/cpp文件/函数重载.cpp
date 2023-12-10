#include <iostream>
using namespace std;


void func2(int a){
    cout<<"func2"<<endl;
}

void func2(int a,int b=10){
    cout<<"func2"<<endl;
}

int main(){
    //func2(10);
    //出错，两个都可以调进去，产生二义性
    return 0;
}