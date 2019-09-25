#include<bits/stdc++.h>
using namespace std;


struct Node{
	int data;
	struct Node *left,*right;
};

Node * addNode(int data)
{
	Node *temp = new Node;
	temp->left = temp->right = NULL;
	temp->data = data;
	return temp;
}

void inorder(Node *root)
{
	if(root == NULL)
		return;
	
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}



void mirror(Node *root)
{
	if(root == NULL)
		return;
		
	queue<Node*> q;
	q.push(root);
	
	while(!q.empty())
	{
		Node *n = q.front();
		cout<<n->data<<" ";
		q.pop();
		
		swap(n->left,n->right);
		
		if(n->left)
			q.push(n->left);
		
		if(n->right)	
			q.push(n->right);
	}
		
}

void recursiveMirror(Node *root)
 {
 	if(root == NULL)
 	 return;
 	
	recursiveMirror(root->left);  
	recursiveMirror(root->right);
	
	Node *temp = new Node;
	temp = root->right;
	root->right = root->left;
	root->left = temp;
 }

int main()
{
	struct Node *a = addNode(1);
	a->left = addNode(2);
	a->right = addNode(3);
	a->left->left = addNode(4);
	a->left->right = addNode(5);
	a->right->left = addNode(6);
	a->right->right = addNode(7);
	
	//inorder(a);
	mirror(a);
	
	cout<<"before"<<endl<<endl;
	inorder(a);
	recursiveMirror(a);
	cout<<"after"<<endl;
	inorder(a);
	
//	cout<<a->left->data<<endl;
}
