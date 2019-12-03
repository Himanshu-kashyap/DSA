#include<bits/stdc++.h>
using namespace std;
 
 class TS
 {
 	deque<int> t;
 	vector<int> *adj;
 	bool *vis;
 	int V;
 	
 	public:
 	TS(int V)
 	{
 		this->V = V;
 		adj = new vector<int>[V];
 		vis = new bool[V];
 		
 		for(int i=0;i<V;i++)
 		 {
 		 	vis[i] = false;
 		 }
 	}
 	
 	
 	//need directed graph and without cycle
 	void addEdge(int u,int v)
 	 {
 	 	adj[u].push_back(v);
 	 }
 	
 	
 	
 	void util(int curr)
 	{
 		vis[curr] = true;
 		for(int i =0;i<V;i++)
 		 {
 		 	if(vis[i] == false and adj[curr][i] == true)
 		 	 util(i);
		  }
		 t.push_front(curr);
	 }
 	
 	void printall()
 	{
 		deque<int> ::iterator itr;
 		for(itr = t.begin();itr!= t.end();itr++)
 		{ 
 			cout<< *itr<<endl;
		 }
	 }
 	
 	
 };
 
 int main()
  {
  	TS t(5);
  	t.addEdge(1,2);
  	t.addEdge(2,3);
  	t.addEdge(2,5);
  	t.addEdge(3,4);
  	
  	t.util(1);
  	t.printall();
  	
  	
  	
  }
