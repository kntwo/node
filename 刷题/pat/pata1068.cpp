#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
bool cmp(int i,int j){
    return i>j;
}
int main(){
	freopen("input.txt","r",stdin);
    int N,M;
    cin>>N>>M;
    int w[10001];
    int dp[10001]={0};
    bool choice[10001][101]={0};
    for(int i=1;i<=N;i++){
        cin>>w[i];
    }
    sort(w+1,w+1+N,cmp);
    for(int i=1;i<=N;i++){
        for(int j=M;j>=w[i];j--){
			if(dp[j]<=dp[j-w[i]]+w[i]){
				choice[i][j]=true;
				dp[j]=dp[j-w[i]]+w[i];
			}
        }
    }
    if(dp[M]!=M){cout<<"No Solution";return 0;}
	vector<int>ans;
	int n=N,m=M;
	while(m>0){
		if(choice[n][m]==true){
			ans.push_back(w[n]);
			m=m-w[n];
		}
		n--;
	}
	for(int i=0;i<ans.size();i++){
		if(i==0)cout<<ans[i];
		else{
			cout<<' '<<ans[i];
		}
	}
    /*cout<<endl;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=M;j++){
            cout<<choice[i][j]<<' ';
        }
        cout<<endl;
    }*/
    return 0;
}
