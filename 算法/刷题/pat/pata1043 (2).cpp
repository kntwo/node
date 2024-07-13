#include<iostream>
#include<vector>
using namespace std;
int N;
vector<int>pre;
struct Node{
    int value;
    Node*left=NULL,*right=NULL;
};
void insertnode(int curid,Node*curnode){
    if(pre[curid]<curnode->value){
        if(curnode->left==NULL){
            Node *temp=new Node;
            temp->value=pre[curid];
            curnode->left=temp;return;
        }else{
            insertnode(curid,curnode->left);
        }
    }else{
        if(curnode->right==NULL){
            Node *temp=new Node;
            temp->value=pre[curid];
            curnode->right=temp;return;
        }else{
            insertnode(curid,curnode->right);
        }
    }
}
void insertnodem(int curid,Node*curnode){
    if(pre[curid]>=curnode->value){
        if(curnode->left==NULL){
            Node *temp=new Node;
            temp->value=pre[curid];
            curnode->left=temp;return;
        }else{
            insertnodem(curid,curnode->left);
        }
    }else{
        if(curnode->right==NULL){
            Node *temp=new Node;
            temp->value=pre[curid];
            curnode->right=temp;return;
        }else{
            insertnodem(curid,curnode->right);
        }
    }
}
vector<int>true_pre;
void potraversal(Node* root){
    true_pre.emplace_back(root->value);
    if(root->left!=NULL)potraversal(root->left);
    if(root->right!=NULL)potraversal(root->right);
}
int num=1;
void potraversal1(Node* root){
    if(root->left!=NULL)potraversal1(root->left);
    if(root->right!=NULL)potraversal1(root->right);
    if(num==N)cout<<root->value<<endl;
    else{
        num++;
        cout<<root->value<<" ";
    }
}
int main(){
    cin>>N;
    Node *root=new Node;
    pre.resize(N);
    for(int i=0;i<N;i++){
        cin>>pre[i];
        if(i==0){
            root->value=pre[i];
        }else{
            insertnode(i,root);
        }
    }
    potraversal(root);
    bool flag=false;
    if(true_pre==pre){
        flag=true;
    }
    if(flag==false){
        true_pre.clear();
        root->left=NULL;
        root->right=NULL;
        for(int i=1;i<N;i++){
            insertnodem(i,root);
        }
        potraversal(root);
        if(true_pre==pre){
            flag=true;
        }
    }
    if(flag==true){
        cout<<"YES"<<endl;
        potraversal1(root);
    }else{
        cout<<"NO";
    }
    return 0;
}
