#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct Node{
	int num_child;
	int value;
	int left=-1,right=-1;
}node[100];
int N;
int val[100];
int cur_no=0;
void Inorder(int curnode){
	if(node[curnode].left!=-1)Inorder(node[curnode].left);
	node[curnode].value=val[cur_no];
	//cout<<node[curnode].value<<' ';
	cur_no++;
	if(node[curnode].right!=-1)Inorder(node[curnode].right);
}
int no=0;
void bfs(int root){
	queue<int>q;
	q.push(root);
	while(!q.empty()){
		int top=q.front();
		q.pop();
		no++;
		if(no==N)cout<<node[top].value;
		else{
			cout<<node[top].value<<' ';
		}
		if(node[top].left!=-1)q.push(node[top].left);
		if(node[top].right!=-1)q.push(node[top].right);
	}
}
int main(){
	freopen("input.txt","r",stdin);
	cin>>N;
	for(int i=0;i<N;i++){
		int lt,rt;
		cin>>lt>>rt;
		if(lt!=-1)node[i].left=lt;
		if(rt!=-1)node[i].right=rt;
	}
	for(int i=0;i<N;i++){
		cin>>val[i];
	}
	sort(val,val+N);
	Inorder(0);
	bfs(0);
	return 0;
}
