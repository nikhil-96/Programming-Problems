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

void rootSum(treeNode* root,int out[],int iter,int sum)
{
	if(root==NULL)
		return;
	
	out[iter] = root->info;
	sum = sum - out[iter];
	
	if(sum==0)
	{
		for(int i=0;i<=iter;i++)
			cout<<out[i]<<" ";
		cout<<endl;
	}
	else if(sum>0)
	{
		rootSum(root->left,out,iter+1,sum);
		rootSum(root->right,out,iter+1,sum);
	}
	
}

void rootToNodeSum(treeNode *root,int sum)
{
	int out[1000];
	rootSum(root,out,0,sum);
}

void rootPath(treeNode *root,int out[],int iter)
{
	if(root==NULL)
		return;
		
	out[iter] = root->info;
	
	if(root->left==NULL && root->right==NULL)
	{
		for(int i=0;i<=iter;i++)
			cout<<out[i]<<" ";
		cout<<endl;
	}
	else
	{
		rootPath(root->left,out,iter+1);
		rootPath(root->right,out,iter+1);
	}
	return;
	
}

void rootToLeafPath(treeNode *root)
{
	int out[1000];
	rootPath(root,out,0);
}

void printAtDistanceK(treeNode *root,int k)
{
	if(root==NULL)
		return;
	
	if(k==0)
	{
		cout<<root->info<<" ";
		return;
	}
	
	printAtDistanceK(root->left,k-1);
	printAtDistanceK(root->right,k-1);
	
	return;
}

int printKDistanceNode(treeNode *root,treeNode *target,int k)
{
	if(root==NULL)
		return -1;

	if(root==target){
		printAtDistanceK(root,k);
		return 0;
	}

	int dl = printKDistanceNode(root->left,target,k);

	if(dl!=-1)
	{
		if(dl+1==k)
			cout<<root->info<<endl;
		else
			printAtDistanceK(root->right,k-dl-2);

		return 1+dl;
	}

	int dr = printKDistanceNode(root->right,target,k);
	if(dr!=-1)
	{
		if(dr+1==k)
			cout<<root->info<<endl;
		else
			printAtDistanceK(root->left,k-dr-2);

		return 1+dr;
	}

	return -1;
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
	
	rootToNodeSum(root,9);
	rootToLeafPath(root);
	printAtDistanceK(root,2);

	cout<<endl;
	int r = printKDistanceNode(root,root->right,2);
	//cout<<r;
	
	return 0;

}
