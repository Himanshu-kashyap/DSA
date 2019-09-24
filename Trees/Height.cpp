#include<bits/stdc++.h>
 using namespace std;

struct Node{
	int data;
	struct Node *left,*right;
};

Node *newNode(int data)
{
	Node *node = new Node;
	node->data = data;
	node->left = node->right = NULL;
}


int height(Node *root)
{
	if(root == NULL)
		return 0;
	else
		return (1+ max(height(root->left),height(root->right)));
}

int main()
{
	Node *root = newNode(1);  
  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
      
    cout << "Height of tree is " << height(root);  
    return 0;  
	


}

