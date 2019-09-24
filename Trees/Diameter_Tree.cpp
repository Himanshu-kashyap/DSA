// diameter might be max of left diameter of tree and right diameter and left/right height of tree
// 



#include<bits/stdc++.h>
 using namespace std;

struct Node
{
	int data;
	struct Node *left,*right;
};

Node* newNode(int data)
{
	Node *temp  = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

int height(Node *root)
{
	if(root == NULL)
		return 0;
	else{
		cout<<"height : "<< 1+max(height(root->left),height(root->right)) <<endl;
		return(1+max(height(root->left),height(root->right)));
	}	
}

int diameter(Node *root,int *height)
{
	int lh = 0,rh =0;
	int ldia =0,rdia =0;
	
	if(root = NULL)
	 {
	 	*height = 0;
	 	return 0; // dia is also 0 
	 }
	 
	 ldia = diameter(root->left,&lh);
	 rdia = diameter(root->right,&rh);
	 
	 *height = max(lh,rh) + 1;
	 cout<<"dia height :"<<height<<endl;
	 
	 return max(lh+rh+1,max(ldia,rdia));
	
}


int main()
{
	
  Node *root = newNode(1); 
  root->left        = newNode(2); 
  root->right       = newNode(3); 
  root->left->left  = newNode(4); 
  root->left->right = newNode(5); 

	int dd = diameter(root,0);
	cout<<"diameter is : "<<dd<<endl;
	return 0;



}

