#include <bits/stdc++.h>
 using namespace std;

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
	
	
	Node(int x)
	{
		data = x;
		left = right = NULL;
	}
	
};

void inorder(struct Node *root)
{
	if(root == NULL)
	return;
	inorder(root->left);
	cout<<root->data<<"\t";
	inorder(root->right);
}

void printLeft(Node *root,int llevel,int rlevel)
{
	if(root == NULL)
	return;
	
	cout<<root->data<<"\t";
	
	if(root->left)
	{
	  llevel++;
	  printLeft(root->left,llevel,rlevel);
	}
	if(root->right and (llevel>rlevel))
	{
		rlevel++;
		printLeft(root->right,llevel,rlevel);
		
	}
	
	
	
	 
	
	
}


int main()
{
	struct Node *root = new Node(3);
	root->left = new Node(5);
	root->right = new Node(6);
	root->left->left = new Node(7);
	root->left->right = new Node(8);
	root->right->left= new Node(9);
	root->right->right= new Node(10);
	
	
//	inorder(root);
	
	printLeft(root,0,0);
	
	
	
}

