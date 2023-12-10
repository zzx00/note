#include <iostream>
#include <algorithm>
using namespace std;

int book[100];          //记录这个点有没有被访问过
int dis[100];           //记录距离树的距离最短的路程
int map[100][100];
#define max 9999

int main(){
    int n,m;            //n个点m条边
    cin>>n>>m;
    int sum=0;
    int minindex,min;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                map[i][j]=0;
            }else{
                map[i][j]=max;
            }
        }
    }
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        map[x][y]=w;
        map[y][x]=w;
    }
    for(int i=1;i<=n;i++){
        dis[i]=map[1][i];
    }
    book[1]=1;
    for(int i=1;i<=n-1;i++){        //因为第一个已经加进去了，所以循环n-1遍
        min=max;
        for(int j=1;j<=n;j++){
            if(book[j]==0&&min>dis[j]){
                minindex=j;
                min=dis[j];
            }
        }
        book[minindex]=1;
        sum+=dis[minindex];
        for(int j=1;j<=n;j++){
            if(book[j]==0&&dis[j]>map[minindex][j]){
                dis[j]=map[minindex][j];
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}