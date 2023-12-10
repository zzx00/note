#include <stack>
#include <iostream>
using namespace std;
int main(){
    //声明一个栈
    stack<int> a;
    //入栈
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    //将栈顶元素弹栈
    a.pop();
    //打印栈顶元素
    cout<<a.top()<<endl;
    //判断栈是否为空
    cout<<a.empty()<<endl;
    //打印栈中元素个数
    cout<<a.size()<<endl;
    return 0;
}