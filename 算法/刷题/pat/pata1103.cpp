#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int N,K,P,n;
int arr[21];
int maxfatorsum=0;
vector<int>path;
vector<int>final_path;
void dfs(int curnode,int curlevel,int curfatorsum,int cursum){
    path.emplace_back(curnode);
    if(curlevel==K){
        if(cursum==N&&curfatorsum>=maxfatorsum){
                maxfatorsum=curfatorsum;
                final_path=path;
    	}
    }else{
        for(int i=1;i<=n;i++){
        	if(i>curnode)break;
            if(cursum+arr[i]<=N){
                dfs(i,curlevel+1,curfatorsum+i,cursum+arr[i]);
            }
        }
    }
    path.pop_back();
}
int main(void){
    cin>>N>>K>>P;
    n=pow(N,1.0/P);
    for(int i=1;i<21;i++){
        arr[i]=pow(i,P);
    }
    for(int i=1;i<=n;i++){
        dfs(i,1,i,arr[i]);
    }
    if(final_path.size()==0){
        printf("Impossible");
        return 0;
    }
    cout<<N<<" = ";
    for(int i=0;i<K;i++){
        if(i==K-1)cout<<final_path[i]<<'^'<<P<<endl;
        else{
                cout<<final_path[i]<<'^'<<P<<" + ";
        }
    }
    return 0;
}
