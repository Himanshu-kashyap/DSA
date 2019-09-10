#include<bits/stdc++.h>
 using namespace std;

//call dfsutil for every node

class Graph
{
	vector <int> *nodes;
	int V;
	public:
	Graph(int V)
	{
		this->V = V;
		nodes = new vector<int>[V];
	}
	
	void addEdge(int u,int v)
	 {
	 	nodes[u].push_back(v);
	 }
	 
	 
	void dfs_util(int s,bool visited[]) 
	 {
	 	visited[s] = true;
	 	cout<<s<<"\t";
		for(vector<int> ::iterator i = nodes[s].begin();i!=nodes[s].end();i++)
	     {
	     	if(!visited[*i])
	     	 dfs_util(*i,visited);
		 }
	 }
	
	void dfs_traversal()
	{
		bool *visited = new bool[V];
		for(int i =0;i<V;i++) visited[i] = false;
		
		for(int i=0;i<V;i++)
		 {
		 	if(!visited[i])
		 	 {
		 	 	dfs_util(i,visited);
			 }
		 }
		
		
		
	}
	
	
};

int main()
{

Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Depth First Traversal\n"; 
    g.dfs_traversal(); 
  
  return 0;

}

