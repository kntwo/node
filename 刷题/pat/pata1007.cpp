#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
vector<int>arr;
vector<int>dp;
int N;
//dp[k]=max(dp[k-1],dp[k-1]+arr[k]);
//dp[0]=arr[0];
int begin=-1,end=-1;
int maxsub(int i){
	if(i==0)return dp[0];
	if(dp[i]==-100000){
		dp[i]=max(arr[i],maxsub(i-1)+arr[i]);
	}
	return dp[i];
}
int main(){
	int N;
	cin>>N;
	arr.resize(N);
	dp.resize(N);
	for(int i=0;i<N;i++){
		cin>>arr[i];
		dp[i]=-100000;
	}dp[0]=arr[0];
	//cout<<maxsub(N-1);
	for(int i:dp){
		cout<<i<<' ';
	}
	return 0;
}
