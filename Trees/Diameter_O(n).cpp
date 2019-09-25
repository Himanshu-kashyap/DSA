// this method is linear as diameter is nothing but max of lh+rh+1 for each node. we go
// through each node once

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
	return node;
}

int height(Node *root,int &ans)
{
	if(root == NULL)
	 return 0;
	 
	int lh = height(root->left,ans); 
	int rh = height(root->right,ans);
	
	ans = max(lh+rh+1,ans);  // for each node dia is max value (lh + rh + 1,prev(lh+rh+1)) 
	
	return(1+max(lh,rh));
}

int diameter(Node *root)
{
	
	if(root == NULL)
		return 0;
	
	int ans = -1;
	int ht = height(root,ans);
	return ans;
}


int main()
{

	struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
  
    printf("Diameter is %d\n", diameter(root)); 
  
    return 0; 

}

