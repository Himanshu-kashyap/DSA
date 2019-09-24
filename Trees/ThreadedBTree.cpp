// threading used for faster inorder traversal
// get leftmost first and start traversing rightwards 
	// if rightthread exists then node = node->right

#include<bits/stdc++.h>
 using namespace std;
 
struct Node{
	int data;
	struct Node *left,*right;
	struct Node *rightThread;
};

Node *newNode(int data)
{
	Node *node = new Node;
	node->data = data;
	node->left = node->right = NULL;
}

Node *leftmost(Node *root)
{
	if(root == NULL)
		return NULL;
		
	while(root->left != NULL)
		 root = root->left;
	
	return root;	 
		
}

void inorder(Node *root)
{
	struct Node *lleft = leftmost(root);
	while(lleft != NULL)
	{
		cout<<lleft->data<<endl;
		
		if(lleft->rightThread)
			lleft = lleft->right;
		else
			lleft = leftmost(lleft->right);
			
		
	}
}

int main()
{

	Node *root = newNode(1);  
  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
      
    inorder(root);
    return 0;  
		

}

