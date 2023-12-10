#include <iostream>
using namespace std;

int fa1[10005];
int fa2[10005];
int fa3[10005];
int find1(int x){
    if(x==fa1[x]){
        return x;
    }
    return fa1[x]=find1(fa1[x]);
}

//迭代
int find2(int x){
    while(x!=fa2[x]){
        x=fa2[x]=fa2[fa2[x]];
    }
    return x;
    
}

//容易理解版本
int find3(int x){
    if(x==fa3[x]){
        return x;
    }else{
        fa3[x]=find3(fa3[x]);
    }
    return fa3[x];
}

//合并fa[find(x)]=find(y);
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        fa1[i]=i;
        fa2[i]=i;
        fa3[i]=i;
    }
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>z>>x>>y;
        if(z==1){
            fa1[find1(x)]=find1(y);
            fa2[find2(x)]=find2(y);
            fa3[find3(x)]=find3(y);
        }else if(z==2){
            if(find1(x)==find1(y)){
                cout<<'Y'<<endl;
            }else{
                cout<<'N'<<endl;
            }
            if(find2(x)==find2(y)){
                cout<<'Y'<<endl;
            }else{
                cout<<'N'<<endl;
            }
            if(find3(x)==find3(y)){
                cout<<'Y'<<endl;
            }else{
                cout<<'N'<<endl;
            }
        }
    }
    return 0;
}