#include<bits/stdc++.h>
 using namespace std;

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

Node *newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void traversal(Node *root)
{
	if(root == NULL)
		return;
		
	queue<Node *> q;
	
	q.push(root);
	while(!q.empty())
	{
		Node *node = q.front();
		cout<<node->data<<endl;
		q.pop();
		
		if(node->left != NULL)
			q.push(node->left);
		
		if(node->right != NULL)
			q.push	(node->right);
	}
	
	
}

int main()
{
	Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
  
  	traversal(root);
  	return 0;


}

