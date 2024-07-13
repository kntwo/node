#include<iostream>
#include<vector>
using namespace std;
vector<int>child[100];
int maxlevel=0,num_eachlevel[100]={0};
void dfs(int curid,int curlevel){
	if(curlevel>maxlevel)maxlevel=curlevel;
	if(child[curid].size()>0){
		for(auto k : child[curid]){
			dfs(k,curlevel+1);
		}
	}else{
		num_eachlevel[curlevel]++;
	}
}
int main(){
	int nn,ulnn;
	cin>>nn>>ulnn;
	int index,k,argu;
	for(int i=0;i<ulnn;i++){
		cin>>index>>k;
		while(k--){
			cin>>argu;
			child[index].push_back(argu);
		}
	}
	dfs(1,1);
    for(int i=1;i<=maxlevel;i++){
    	if(i>1)cout<<' ';
    	cout<<num_eachlevel[i];
	}
	return 0;
}
