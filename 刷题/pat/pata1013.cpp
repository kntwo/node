#include<iostream>
#include<vector>
using namespace std;
//input
//3 2 3
//1 2
//1 3
//1 2 3
//output
//1
//0
//0
//calculate linked sub-diagram
int acity,hwnum,ckcity;
bool visit[1000];
vector<int>m[1000];
void dfs(int curcity){
	if(visit[curcity]==true){
		return;
	}
	visit[curcity]=true;
	for(int i=0;i<m[curcity].size();i++){
		dfs(m[curcity][i]);
	}
}
int main(){
	cin>>acity>>hwnum>>ckcity;
	int startc,endc;
	while(hwnum--){
		cin>>startc>>endc;
		m[startc].push_back(endc);
		m[endc].push_back(startc); 
	}
	while(ckcity--){
		int lost;
		cin>>lost;
		for(int i=0;i<1000;i++)visit[i]=false;
		visit[lost]=true;
		int sub_diagram=0;
		for(int i=1;i<=acity;i++){
			if(visit[i]==false){
				dfs(i);
				sub_diagram++;
			}
		}
		cout<<sub_diagram-1<<endl;
	}
	return 0;
}

