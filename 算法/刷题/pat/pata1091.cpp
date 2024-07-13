#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Node{
	int i,j,k;
};
int M,N,L,T;
        //level row column
int brain[60][1286][128]={0};
bool visit[60][1286][128]={false};
int l[6]={0,0,0,0,1,-1};
int r[6]={1,-1,0,0,0,0};
int c[6]={0,0,-1,1,0,0};
int ans=0;
bool judge(int i,int j,int k){
	if(i>=0&&i<L&&j>=0&&j<M&&k>=0&&k<N&&!visit[i][j][k]&&brain[i][j][k])return true;
	else{
		return false;
	}
}
int bfs(int i,int j,int k){
	visit[i][j][k]=true;
	queue<Node>q;
	Node root;
	root.i=i;root.j=j;root.k=k;
	q.push(root);
	int count=0;
	while(!q.empty()){
		Node top=q.front();
		q.pop();
		count++;
		for(int i=0;i<6;i++){
			int level=top.i+l[i];
			int row=top.j+r[i];
			int column=top.k+c[i];
			if(judge(level,row,column)){
				visit[level][row][column]=true;
				Node temp;
				temp.i=level;temp.j=row;temp.k=column;
				q.push(temp);
			}
		}
	}
	return count;
}
int main(){
	freopen("input.txt","r",stdin);
	cin>>M>>N>>L>>T;
	for(int i=0;i<L;i++){
		for(int j=0;j<M;j++)
			for(int k=0;k<N;k++)
				cin>>brain[i][j][k];
	}
	for(int i=0;i<L;i++){
		for(int j=0;j<M;j++)
			for(int k=0;k<N;k++){
				if(!visit[i][j][k]&&brain[i][j][k]){
					int temp=bfs(i,j,k);
					if(temp>=T)ans=ans+temp;//ans=ans+temp;
				}
			}
	}
	cout<<ans;
}
