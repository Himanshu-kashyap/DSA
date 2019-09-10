#include<bits/stdc++.h>
 using namespace std;



struct compare{
	bool operator()(const int& l, const int& r)
	 {
	 	return l<r;
	 }
};

priority_queue<int,vector<int>,greater<int> > g;

int main()
{
 int n;cin>>n;
 int arr[n];
   for(int i=0;i<n;i++)
    {
	cin>>arr[i];
	g.push(arr[i]);
	}
  int c = 0;
  while(g.size() != 1 )
    {
    	int a = g.top();g.pop();
    	int b = g.top();g.pop();
    	g.push(a+b);
    	c = c+a+b;
	}
	
	
	 cout<< c;
  	
  	return 0;
    

}

