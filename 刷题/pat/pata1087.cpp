#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<map>
using namespace std;
int N,K;
string startcity;
map<string,int>cityno;
map<int,string>cityname;
int happiness[201]={0};
int u_map[201][201];
vector<int>adjacent[201];
int mincost[201];
vector<int>path;
int endcity;
vector<int>final_path;
int final_happ=0,final_avghapp=0,final_num=1;
void dfs(int curnode,int curcost,int curhapp,int avghapp,int curnum){
    if(curcost>mincost[curnode])return;
    path.emplace_back(curnode);
    if(curnode==endcity){
    	if(curcost<mincost[endcity]){
            final_num=1;
        }else{
          	final_num++;
		}
        if(curcost<mincost[endcity]||(curcost==mincost[endcity]&&curhapp>final_happ)||(curcost==mincost[endcity]&&curhapp==final_happ&&avghapp>final_avghapp)){
			final_path=path;
            mincost[endcity]=curcost;
            final_happ=curhapp;
            final_avghapp=avghapp;
        }
    }else{
        mincost[curnode]=curcost;
        for(int i:adjacent[curnode]){
            dfs(i,curcost+u_map[curnode][i],curhapp+happiness[i],(curhapp+happiness[i])/(curnum+1),curnum+1);
        }
    }
    path.pop_back();
}
int main(){
	freopen("input.txt","r",stdin);
    cin>>N>>K>>startcity;
    int n=N-1;
    int cityn=1;
    cityno.insert(pair<string,int>(startcity,cityn));
    cityname.insert(pair<int,string>(cityn,startcity));  
    while(n--){
        cityn++;
        string city;
        int happy;
        cin>>city>>happy;
        happiness[cityn]=happy;
        cityno.insert(pair<string,int>(city,cityn));
        cityname.insert(pair<int,string>(cityn,city)); 
    }
    while(K--){
        string start_r,end_r;
        int cost;
        cin>>start_r>>end_r>>cost;
        int a=cityno[start_r],b=cityno[end_r];
        u_map[a][b]=u_map[b][a]=cost;
        adjacent[a].emplace_back(b);
        adjacent[b].emplace_back(a);
    }
    for(int i=0;i<201;i++)mincost[i]=100000;
    endcity=cityno["ROM"];
    dfs(1,0,0,0,0);
    cout<<final_num<<' '<<mincost[endcity]<<' '<<final_happ<<' '<<final_avghapp<<endl;
    for(int i:final_path){
    	cout<<cityname[i]<<"->";
	}
    return 0;
}
