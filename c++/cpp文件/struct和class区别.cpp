#include <iostream>
using namespace std;

class c1{
    int m_a;//默认为私有
};

struct c2{
    int m_a;//默认为公共
};

int main(){
    c1 c;
    c2 b;
    //c.m_a=1;不能访问，为私有
    b.m_a=1;
}