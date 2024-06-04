#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
//output
//family sum
//ID M avgsets avgarea //smallest ,sum of family mem,order by (abgarea desc,ID)
int N;//<=1000
int father[10000],Mestate[10000]={0},area[10000]={0};
struct ANS{
	bool visit;
	int id;
	double summestate,sumarea;
	vector<int>list;
}ans[10000];
vector<ANS>final;
bool visit[10000]={0};
int findfather(int i){
	if(father[i]==i)return i;
	else{
		int F=findfather(father[i]);
		father[i]=F;
		return F;
	}
}
void Union(int a,int b){
	int FAa=findfather(a);
	int FAb=findfather(b);
	if(FAa<=FAb){
		father[FAb]=FAa;
	}else{
		father[FAa]=FAb;
	}
}
bool cmp(ANS a,ANS b){
	double as=a.sumarea/a.list.size();
	double bs=b.sumarea/b.list.size();
	if(as!=bs)return as>bs;
	return a.id<b.id;
}
int main(){
	//freopen("input.txt","r",stdin);
	cin>>N;
	for(int i=0;i<10000;i++){
		father[i]=i;
		ans[i].visit=false;
		ans[i].sumarea=ans[i].summestate=0;
		ans[i].id=i;
	}
	while(N--){
		int id,fa,mo,cn,cid,mest,ar;
		cin>>id>>fa>>mo>>cn;
		visit[id]=true;
		if(fa!=-1){
			visit[fa]=true;
			Union(fa,id);
		}
		if(mo!=-1){
			visit[mo]=true;
			Union(mo,id);
		}
		while(cn--){
			int child;
			cin>>child;
			visit[child]=true;
			Union(id,child);
		}
		cin>>mest>>ar;
		Mestate[id]=mest;
		area[id]=ar;
	}
	int ansfront=0;
	for(int i=0;i<10000;i++){
		if(ans[i].visit==false&&visit[i]==true){
			int temp=findfather(i);
			if(ans[temp].list.size()==0)ansfront++;
			ans[temp].visit=true;
			ans[temp].list.push_back(i);
			ans[temp].sumarea+=area[i];
			ans[temp].summestate+=Mestate[i]; 
		}
	}
	for(int i=0;i<10000;i++){
		if(ans[i].list.size()!=0)final.push_back(ans[i]);
	}
	sort(final.begin(),final.end(),cmp);
	cout<<ansfront<<endl;
	for(int i=0;i<ansfront;i++){
		double ans3=final[i].list.size();
		printf("%04d %d %.3f %.3f\n",final[i].id,final[i].list.size(),final[i].summestate/ans3,final[i].sumarea/ans3);
	}
	return 0;
}