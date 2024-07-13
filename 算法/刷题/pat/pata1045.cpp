#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int N,M,L;
//dp[i]=1; not find j<=i before i
//dp[i]=dp[j]+1; if(dp[j]+1>dp[i]) find all j before i
int main(){
	freopen("input.txt","r",stdin);
	int stripe[10001],dp[10001]={0};
	map<int,int>order;
	map<int,int>rvsorder;
    cin>>N>>M;
    int maxans=0;
	for(int i=1;i<=M;i++){
		int num;
		cin>>num;
		order[num]=i;
		rvsorder[i]=num;
	}
	cin>>L;
	for(int i=1;i<=L;i++){
		cin>>stripe[i];
		map<int,int>::iterator it=order.find(stripe[i]);
		if(it==order.end()){
			stripe[i]=-1;
		}else{
			stripe[i]=it->second;
			maxans=1;
		}
	}
	if(stripe[1]>0)dp[1]=1;
	for(int i=2;i<=L;i++){
		int isfind=0;
		for(int j=1;j<=i-1;j++){
			if(stripe[j]<=stripe[i]&&stripe[j]!=-1&&dp[j]+1>dp[i]){
				isfind=1;
				dp[i]=dp[j]+1;
				if(dp[i]>maxans)maxans=dp[i];
			}
		}
		if(isfind==0&&stripe[i]!=-1){
			dp[i]=1;
		}
	}
	cout<<maxans;
    return 0;
}
