#include <iostream>
#include <algorithm>
using namespace std;
int fa[5005];
bool flag[5005]={0};
int find(int num){
	if(fa[num]==num){
		return num;
	}else{
		while(fa[num]!=num){
			num=fa[num]=fa[fa[num]];
		}
		return num;
	}
}


struct node{
	int a,b;
	int value;
};
bool cmp(node a1,node b1){
	return a1.value<b1.value;
}
node c[200005];
int main() {
	int n,m;
	cin>>n>>m;
	if(m<n){
		cout<<"orz"<<endl;
		return 0;
	}
	for(int i=0;i<m;i++){
		cin>>c[i].a>>c[i].b>>c[i].value;
	}
	sort(c,c+m,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int num=0;
	for(int i=0;i<m;i++){
		if(find(c[i].a)!=find(c[i].b)){
			fa[find(c[i].a)]=fa[find(c[i].b)];
			num+=c[i].value;
			flag[c[i].a]=flag[c[i].b]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(flag[i]==0){
			cout<<"orz"<<endl;
			return 0;
		}
	}
	cout<<num<<endl;
	return 0;
}