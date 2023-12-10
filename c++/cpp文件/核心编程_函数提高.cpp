#include <iostream>
using namespace std;

// int func(int a,int b=10,int c=10){
//     return a+b+c;
// }

//如果某个位置有了默认参数，那么从这个位置往后，从左到右都必须有默认参数
//int func(int a,int b=10,int c){}这样不行


//如果函数声明有默认参数，那么函数的实现不能有默认参数
// int func(int a=10,int b=10);

// int func(int a=10,int b=10){
//     return a+b;
// }
//不行

void func(int a,int){
    cout<<"函数被调用"<<endl;
}

int main(){
    func(20,10);
    return 0;
}