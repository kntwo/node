#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>hobby[1001];
int father[1001];
int N;
int ans[1001]={0};
int findfather(int i){
    if(father[i]==i)return i;
    else{
        int f=findfather(father[i]);
        father[i]=f;
        return f;
    }
}
void Union(int a,int b){
    int FTa=findfather(a);
    int FTb=findfather(b);
    if(FTa!=FTb)father[FTb]=FTa;
}
int main(){
    cin>>N;
    for(int i=1;i<=N;i++)father[i]=i;
    for(int i=1;i<=N;i++){
        int numhob;
        cin>>numhob;
        getchar();
        while(numhob--){
            int hob;
            cin>>hob;
            hobby[i].emplace_back(hob);
                for(int j=1;j<i;j++){
                    vector<int>::iterator it=find(hobby[j].begin(),hobby[j].end(),hob);
                    if(it!=hobby[j].end()){
                        Union(i,j);
                    }
                }
        }
    }
    int ansfront=0;
    for(int i=1;i<=N;i++){
        int root=findfather(i);
        if(ans[root]==0)ansfront++;
        ans[root]++;
    }
    cout<<ansfront<<endl;
    sort(ans+1,ans+N+1);
    reverse(ans+1,ans+N+1);
    for(int i=1;i<=ansfront;i++){
        if(i==1)cout<<ans[i];
        else{
            cout<<' '<<ans[i];
        }
    }
    cout<<endl;
    return 0;
}