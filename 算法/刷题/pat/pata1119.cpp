#include <iostream>
#include <cstdio>
using namespace std;

struct Node {
	int value = 0;
	Node *left, *right;
};
int numnode;
int preor[30];
int postor[30];
bool unique = true;

Node *CreateTree(int prel, int prer, int postl, int postr) {
	if (prel > prer)
		return NULL;
	Node *root = new Node;
	root->value = postor[postr];
	int k_2=0;
    if(postr-postl==0)return root;
	for (int i = prel; i <= prer; i++) {
		if (postor[postr - 1] == preor[i])
			k_2 = i;
	}
	int numleft = k_2 - (prel + 1);
	if (k_2 == prel + 1)
		unique = false;
	root->left = CreateTree(prel + 1, k_2 - 1, postl, postl + numleft - 1);
	root->right = CreateTree(k_2, prer, postl + numleft, postr - 1);
	return root;
}
int num=0;
void inorder(Node *root) {
	if (root->left != NULL)
		inorder(root->left);
    if(num==numnode-1){
        cout<<root->value<<endl;
    }else{
        num++;
        cout << root->value<<' ';
    }
	if (root->right != NULL)
		inorder(root->right);
}

int main() {
	cin >> numnode;
	for (int i = 0; i < numnode; i++)
		cin >> preor[i];
	for (int i = 0; i < numnode; i++)
		cin >> postor[i];

	Node *root = CreateTree(0, numnode - 1, 0, numnode - 1);
	if (unique == false)
		cout << "No" << endl;
	else {
		cout << "Yes" << endl;
	}
	inorder(root);
	return 0;
}