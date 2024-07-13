#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int N;
int given[1000];
bool ismirror=false;
vector<int>post;
void getpost(int pl,int pr){
	if(pl>pr)return;
	int i=pl+1,j=pr;
	if(!ismirror){
		while(i<=pr&&given[i]<given[pl])i++;
		while(j>pl&&given[j]>=given[pl])j--;
	}else{
		while(i<=pr&&given[i]>=given[pl])i++;
		while(j>pl&&given[j]<given[pl])j--;
	}
	if(i-j!=1)return;
	getpost(pl+1,j);
	getpost(i,pr);
	post.push_back(given[pl]);	
}
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>given[i];
	}
	getpost(0,N-1);
	if(post.size()!=N){
		ismirror=true;
		post.clear();
		getpost(0,N-1);
	}
	if(post.size()==N){
		cout<<"YES"<<endl;
		for(int i=0;i<post.size();i++){
			if(i==post.size()-1)cout<<post[i]<<endl;
			else{
				cout<<post[i]<<' ';
			}
		}
	}else{
		cout<<"NO";
	}
	return 0;
}
