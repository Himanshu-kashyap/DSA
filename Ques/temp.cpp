#include<bits/stdc++.h>
 using namespace std;

struct node{
	int data;
	struct node *next;
	
};

void addEdge(node *head,int data)
{

	node *temp = new node;
	temp->data = data;
	temp->next = NULL;
	
	node *ptr = head;
	
	if(head == NULL)
	{
		head = temp;
		return;
	}
	while(ptr->next)
	{
		ptr = ptr->next;
	}
	ptr->next = temp;
	cout<<"added "<<temp->data<<endl;
	return;
}

int traversalChange(node *head)
{
	node *temp = head;
	node *holder = new node;
	node *change = new node;
	while(temp->next)
	{
		change = temp;
		if((temp->data)%2 == 0 and (temp->next->data) %2 == 0)
		{
			holder = change;
			change->next = change;
			temp = temp->next;
		}
		if((temp->next->data) %2 != 0 and (temp->data)%2 == 0)
		{
			holder->next = change->next;
			temp = temp->next;
		}
	} 
}

int traversal(node *head)
 {
 	node *temp = head;
 	while(temp->next)
 	 {
 	 	cout<<temp->data<<endl;
 	 	temp = temp->next;
 	 	
	  }
 }

int main()
{

int arrsize;
cin>>arrsize;
int arr[arrsize];

node *head = new node;
head->data = 0;
head->next = NULL;

for(int i=0;i<arrsize-1;i++)
	{
		cin>>arr[i];
		addEdge(head,arr[i]);
	}
	
	traversal(head);
	traversalChange(head);
	traversal(head);
}

