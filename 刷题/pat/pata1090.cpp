#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
using namespace std;
int N;
double P,r;
struct Node{
	vector<int>child;
}node[100000];
int maxlevel=0;
int max_l_num;
void dfs(int curnode,int curlevel){
	if(node[curnode].child.size()==0){
		if(curlevel>maxlevel){
			maxlevel=curlevel;
			max_l_num=1;
		}else if(curlevel==maxlevel){
			max_l_num++;
		}
	}else{
		for(int i=0;i<node[curnode].child.size();i++){
			dfs(node[curnode].child[i],curlevel+1);
		}
	}
}
int main(){
	freopen("input.txt","r",stdin);
	cin>>N>>P>>r;
	int root;
	for(int i=0;i<N;i++){
		int num;
		cin>>num;
		if(num!=-1){
			node[num].child.push_back(i);
		}else{
			root=i;
		}
	}
	dfs(root,0);
	r=r/100;
	printf("%.2f %d",pow((1+r),maxlevel)*P,max_l_num);
	return 0;
}
