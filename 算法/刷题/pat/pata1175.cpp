//easiest way is not unique,  maximum total value of vouchers.
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
struct Node{
    int indegree;
    vector<int>father;
    vector<int>child;
}map[1000];
int N,M,T1,T2,S,D,score[1000][1000],value[1000][1000];
queue<int>avg;int num_avg;
int K,test[1000];
vector<int>path;
vector<int>final_path;
int minscore=10000000,maxvocher;
void dfs(int index,int curscore,int curvocher){
    if(curscore>minscore)return;
    path.emplace_back(index);
    if(map[index].child.size()==0){
        if(curscore<minscore||(curscore==minscore&&curvocher>maxvocher)){
            final_path=path;minscore=curscore;maxvocher=curvocher;
        }
    }else{
        for(int i=0;i<map[index].child.size();i++){
            int k=map[index].child[i];
            dfs(k,curscore+score[k][index],curvocher+value[k][index]);
        }
    }
    path.pop_back();
}

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        map[i].indegree=0;
    }
    while(M--){
        cin>>T1>>T2>>S>>D;
        map[T2].child.emplace_back(T1);
        map[T2].indegree++;
        map[T1].father.emplace_back(T2);
        score[T1][T2]=S;
        value[T1][T2]=D;
    }
    for(int i=0;i<N;i++){
        if(map[i].indegree==0)avg.push(i);
    }
    while(!avg.empty()){
        int t=avg.front();
        avg.pop();
        num_avg++;
        for(int i=0;i<map[t].father.size();i++){
            int t1=map[t].father[i];
            map[t1].indegree--;
            if(map[t1].indegree==0)avg.push(t1);
        }
    }
    cin>>K;
    for(int i=0;i<K;i++){
        cin>>test[i];
    }
    if(num_avg==N){
        cout<<"Okay.\n";
        for(int i=0;i<K;i++){
            if(map[test[i]].child.size()==0)
                printf("You may take test %d directly.\n",test[i]);
            else{
                final_path.clear();minscore=10000000;maxvocher=0;
                dfs(test[i],0,0);
                for(int j=final_path.size()-1;j>=0;j--){
                    if(j==final_path.size()-1)printf("%d",final_path[j]);
                    else printf("->%d",final_path[j]);
                }
                cout<<endl;
            }
        }
    }
    else {
        cout<<"Impossible.\n";
        for(int i=0;i<K;i++){
            if(map[test[i]].child.size()==0)
                printf("You may take test %d directly.\n",test[i]);
            else printf("Error.\n");
        }
    }
    return 0;
}