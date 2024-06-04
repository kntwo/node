#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
//dp[i][j]=dp[i+1][j-1];when s[i]==s[j]
//dp[i][j]=0; when s[i]!=s[j]
int main(){
	freopen("input.txt","r",stdin);
	string s;
	int ans;
	getline(cin,s);
	int len=s.length();
	bool dp[1000][1000]={false};
	for(int i=0;i<len;i++){
		dp[i][i]=1;
		if(i<len-1&&s[i]==s[i+1]){
			dp[i][i+1]=1;
			ans=2;	
		}
	}
	for(int i=2;i<len;i++){
		for(int j=0;j<len-i;j++){
			if(s[j]==s[j+i]){
				dp[j][j+i]=dp[j+1][j+i-1];
				if(dp[j][j+i]==1){
					ans=i+1;
				}
			}
			else{
				dp[j][j+i]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
