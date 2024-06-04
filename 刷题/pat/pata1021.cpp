#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>tree[10001];
bool visit[10001]={false};
vector<int>final_node;
int level[10001]={0};
int maxlevel=0;
int N,subtree=0;
void dfs(int curnode){
	visit[curnode]=true;
	for(int i : tree[curnode]){
		if(visit[i]==false){
			dfs(i);	
		}
	}

}
void dfs(int curnode,int curlevel){
	if(curlevel>maxlevel){maxlevel=curlevel;}
	level[curnode]=curlevel;	
	visit[curnode]=true;
	for(int i :tree[curnode]){
		if(visit[i]==false){
			dfs(i,curlevel+1);
		}
	}

}
int main(){
	cin>>N;
	int linen=N-1;
	while(linen--){
		int start,end;
		cin>>start>>end;
		tree[start].emplace_back(end);
		tree[end].emplace_back(start);
	}
	for(int i=1;i<=N;i++){
		if(visit[i]==false){
			dfs(i);
			subtree++;
		}
	}
	//if only have one subtree
	for(int i=0;i<=N;i++){
		visit[i]=0;
	}
	if(subtree==1){
		dfs(1,1);
		for(int j=1;j<=N;j++){
			if(level[j]==maxlevel)final_node.emplace_back(j);
			level[j]=0;
			visit[j]=0;
		}
		maxlevel=0;
		dfs(final_node[0],1);
		for(int j=1;j<=N;j++){
			if(level[j]==maxlevel){
                int flag=1;
                for(int n:final_node){
                    if(j==n)flag=0;
                }
                if(flag==1)final_node.emplace_back(j);
            }
		}			
		sort(final_node.begin(),final_node.begin()+final_node.size());
		for(int i : final_node){
			cout<<i<<endl;
		}
	}else{
		cout<<"Error: "<<subtree<<" components";	

	}
	return 0;
}
