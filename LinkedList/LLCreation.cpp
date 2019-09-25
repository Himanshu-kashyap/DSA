#include<bits/stdc++.h>
 using namespace std;
struct Node{
	int data;
	struct Node *next;
	
};

void addEdge(Node *head, int data)
{
	
	struct Node *temp = new Node;
	temp->next = NULL;
	temp->data = data;
	
	struct Node *last = head;
	
	if(head == NULL)
	{
		head = temp;
		return;
	}
	
	while(last->next)
		last = last->next;
	
	last->next = temp;
	return ;
}


void invertList(Node *head)
{
	while(head->next != NULL)
	{
		
		if((head->data)%2 == 0)
		{
			Node *temp = new Node;
			temp = head;
			while(head->next->data %2)
				head = head->next;
			
			Node *temp2 = new Node;
			temp2 = temp;
			temp = head;
			head = temp2;
		}
		head= head->next;
	}
}

void printList(Node *head)
{
	while(head->next)
		{
			cout<<head->data<<" ";
			head = head->next;
		}
		cout<<endl;
}

int main()
{

	int arr[] = {2,18,24,3,5,7,9,6,12};
	int sizearr = sizeof(arr)/sizeof(arr[0]);
	
	struct Node *head = new Node;
	head->data = arr[0];
	head->next = NULL;
	
	
	for(int i=1;i<sizearr;i++)
		addEdge(head,arr[i]);
	
	printList(head);
	
	invertList(head);
//	
	printList(head);
//	


}

