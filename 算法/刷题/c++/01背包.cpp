#include <iostream>
#include <cstdio>
//5 8
//3 5 1 2 2
//4 5 2 1 3
using namespace std;
int main(){
	freopen("input","r",stdin);
	int n,V;			 //i , v    ans=dp[n][V];
	//dp[i][v]=max(dp[i-1][v],dp[[i-1][v-w[i]]+c[i]);
	int w[1000],c[1000],dp[1000][1000]={0};
	cin>>n>>V;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=V;i++){
		if(w[1]<=i)dp[1][i]==c[i];
	}
	for(int i=2;i<=n;i++){
		for(int v=0;v<=V;v++){
			if(v>=w[i])dp[i][v]=max(dp[i-1][v],dp[i-1][v-w[i]]+c[i]);
			else{
				dp[i][v]=dp[i-1][v];
			}
		}
	}
	cout<<dp[n][V];
	return 0;
}
