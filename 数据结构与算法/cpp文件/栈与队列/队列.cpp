#include <iostream>
#include <queue>
using namespace std;

int main(){
    //声明一个队列
    queue<int> a;
    //入队
    a.push(1);
    a.push(2);
    //取队首元素（不删除）
    cout<<a.front()<<endl;
    //出队
    a.pop();
    //是否为空
    cout<<a.empty()<<endl;
    //返回元素个数
    cout<<a.size()<<endl;
    //返回队尾元素
    cout<<a.back()<<endl;
    return 0;
}
