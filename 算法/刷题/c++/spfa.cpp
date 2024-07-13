#include<iostream>
#include<queue>
#include<cstring>
#include<stack>
using namespace std;
#define N 100005
#define M 200005
int n,m;
int h[N],e[M],w[M],ne[M],idx;
long long dist[N];
bool st[N];
queue<int>q;
int pre[N];
void add(int a,int b,int c){
	e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
void spfa(){
	memset(pre,-1,sizeof pre);
	dist[1]=0;
	q.push(1);
	st[1]=true;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		st[t]=false;
		for(int i=h[t];i!=-1;i=ne[i]){
			int j=e[i];
			if(dist[j]>dist[t]+w[i]){
				dist[j]=dist[t]+w[i];
				pre[j]=t;
				if(!st[j]){
					q.push(j);
					st[j]=true;
				}
			}
		}
	}
	
}
int main(){
	int n,m;
	int a,b,c;
	memset(dist,0x3f,sizeof dist);
	memset(h,-1,sizeof h);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	spfa();
/*	for(int i=1;i<=n;i++){
		cout<<dist[i]<<' ';
	}*/
	if(pre[n]==-1)cout<<"-1";
	else{
		stack<int>path;
		for(int i=n;i!=-1;i=pre[i]){
			path.push(i);
		}
		while(!path.empty()){
			int temp=path.top();
			path.pop();
			cout<<temp<<' ';
		}
	}
	system("pause"); 
	return 0;
} 
/*
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
*/
