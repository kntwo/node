#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
struct Node{
	int value;
	Node *left;
	Node *right;
};
stack<int>input;
vector<int>preorder;
vector<int>inorder;
int N;
Node* CreateTree(int pl,int pr,int il,int ir){
	if(pl>pr)return NULL;
	Node* root=new Node;
	root->value=preorder[pl];
	int k;
	for(int i=il;i<=ir;i++){
		if(inorder[i]==preorder[pl])k=i;
	}int numleft=k-il;
	root->left=CreateTree(pl+1,pl+numleft,il,k-1);
	root->right=CreateTree(pl+numleft+1,pr,k+1,ir);
	return root;
}
int sumnode=0;
void postorder(Node*root){
	if(root==NULL)return;
	postorder(root->left);
	postorder(root->right);
	if(sumnode==N){
		cout<<root->value;
	}else{
		sumnode++;
		cout<<root->value<<' ';
	}
}
int main(){
	freopen("input.txt","r",stdin);
	cin>>N;
	int n=N*2;
	while(n--){
		string str01;
		int num_no;
		cin>>str01;
		if(str01=="Push"){
			cin>>num_no;
			input.push(num_no);
			preorder.push_back(num_no);
		}else{
			inorder.push_back(input.top());
			input.pop();
		}
	}
	Node*root =CreateTree(0,N-1,0,N-1);
	postorder(root);
	return 0;
}
