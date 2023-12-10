#include <iostream>
#include <queue>

using namespace std;
int main(){
    //优先队列的声明
    //升序队列
    priority_queue<int,vector<int>,greater<int> >q;
    //降序队列，直接声明默认降序
    priority_queue<int,vector<int>,less<int> >p;
    priority_queue<int> a;

    //pair的比较，先比较第一个，再比较第二个
    priority_queue<pair<int,int> >b;
    pair<int,int> m(1,2);
    pair<int,int> n(1,3);
    pair<int,int> o(2,3);
    b.push(m);
    b.push(n);
    b.push(o);
    while(!b.empty()){
        cout<<b.top().first<<' '<<b.top().second<<endl;
        b.pop();
    }
    cout<<endl;
    return 0;
}