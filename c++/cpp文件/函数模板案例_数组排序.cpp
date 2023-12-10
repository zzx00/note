#include <iostream>
#include <string>
#include <cstring>
using namespace std;


template<typename T>
void mySort(T arr[],int len){
    for(int i=0;i<len;i++){
        int max=i;
        for(int j=i+1;j<len;j++){
            if(arr[j]>arr[max]){
                max=j;
            }
        }
        if(max!=i){
            swap(arr[max],arr[i]);
        }
    }
}

template<typename T>
void myPrint(T a[],int len){
    for(int i=0;i<len;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
}

void test01(){
    char ch[]="asdgnfdsef";
    int a[15]={5,2,6,4,12,67,76453,54,75,7452,4,1,0,1,0};
    mySort(ch,strlen(ch));
    myPrint(ch,strlen(ch));
    mySort(a,15);
    myPrint(a,15);
}

int main(){
    test01();
}