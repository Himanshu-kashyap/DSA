#include<bits/stdc++.h>
 using namespace std;
int main()
{
	int arrsize;
	cin>>arrsize;
	int arr[arrsize];
	for(int i=0;i<arrsize;i++)
		cin>>arr[i];
	
	
	stack<int> st;
	//cout<<"st top"<<st.top()<<endl;
	
	int i = 0;
	while(i < arrsize)
	{
		while(arr[i]%2 == 0)	
		{
			st.push(arr[i]);
			i++;
		}
		
		while(!st.empty())
		{
			cout<<st.top()<<"st"<<endl;
			st.pop();
		}
		cout<<arr[i]<<"ll"<<endl;
		i++;
		
	}

}

