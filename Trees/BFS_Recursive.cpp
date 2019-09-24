#include<bits/stdc++.h>
 using namespace std;

struct Node{
	int data;
	struct Node *left,*right;
};

Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
	
}

int height(Node *node)
{
	if(node == NULL)
		return 0;
	
	int lh = height(node->left);
	int rh = height(node->right);
//	cout<<lh<<"--"<<rh<<endl;
	
	return ((lh>rh)?lh+1:rh+1);   // this is the main calculation 0, 0+1 [if left>right return left+1
}

void printLevel(Node *node,int level)
{
	if(node == NULL)
		return;
	
	if(level == 1)	
	{
		cout<<node->data<<endl;
	}
	else
	{
		printLevel(node->left,level-1);
		printLevel(node->right,level-1);
	}
}

void levelOrder(Node *root)
{
//	int h = height(root);
	cout<<"h -- "<<h<<endl;
	for(int i = 1; i<=h ;i++)
		printLevel(root,i);
	
}



int main()
{
	Node *root = newNode(1);  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
  
    cout << "Level Order traversal of binary tree is \n";  
    levelOrder(root);  
  
    return 0;  

}

