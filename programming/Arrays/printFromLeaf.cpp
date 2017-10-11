#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct tree {
	int info;
	struct tree *left;
	struct tree *right;
};

typedef struct tree treeNode;

treeNode* createTreeNode(int info,treeNode *left, treeNode *right)
{
	treeNode *newNode = (treeNode*)malloc(sizeof(treeNode));
	newNode->info = info;
	newNode->left = left;
	newNode->right = right;
	
	return newNode;
}

void inorder(treeNode *root)
{
	if(root==NULL)
		return;
	
	inorder(root->left);
	cout<<root->info<<" ";
	inorder(root->right);
}

void insertBST(treeNode **rootRef,int info)
{
	if(*rootRef == NULL)
	{
		*rootRef = createTreeNode(info,NULL,NULL);
		return;
	}
	
	if(info < (*rootRef)->info)
	{
		insertBST(&((*rootRef)->left),info);
	}
	
	else
		insertBST(&((*rootRef)->right),info);
	
}

void printFromLeaf(treeNode *root)
{
	if(!root)
		return;
	if(root->left==NULL)
		printFromLeaf(root->right);
	if(root->right==NULL)
		printFromLeaf(root->left);

	if(root->left && root->right)
	{
		if(root->left->left==NULL && root->left->right==NULL)
		cout<<root->info<<" ";

	else{

		if(root->right->left==NULL && root->right->right==NULL)
			cout<<root->info<<" ";
		} 
	}
	
	printFromLeaf(root->left);
	printFromLeaf(root->right);

	return;
}

int main()
{
	treeNode *root = NULL;
	insertBST(&root,4);
	
	insertBST(&root,2);
	insertBST(&root,6);
	insertBST(&root,1);
	insertBST(&root,3);
	insertBST(&root,5);
	
	insertBST(&root,7);
	
	inorder(root);
	cout<<endl;
	
	printFromLeaf(root);
	
	return 0;

}