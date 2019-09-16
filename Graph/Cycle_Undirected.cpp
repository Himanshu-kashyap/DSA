#include<bits/stdc++.h>
 using namespace std;


// detecting cycle in directed graph

class DirectedCycle{
	
	vector<int> *adj;  // need new keyword bc it's a pointer to the vector of int
	int V;  // total number of vertices
	vector<int> ::iterator i; // iterator for linked list 
	
//	void isCyclicUtil(int v,bool visited[],bool *recStack); // used by cyclic fxn and takes vertex,visited and recursive stack
	
	
	public:
	// constructor
	DirectedCycle(int V){
		this->V = V;
		adj = new vector<int> [V];  
	}
	
	// adding edges
	void addEdge(int u,int v){
		adj[u].push_back(v);
	}
	
	bool isCyclicUtil(int v,bool visited[],bool *recStack){
		
		if (visited[v] == false) 
		{
			visited[v] = true;
			recStack[v] = true;
			
			for(i = adj[v].begin();i!= adj[v].end();i++)
			 {
			 	if( !visited[*i] && isCyclicUtil(*i,visited,recStack))
			 		return true;
			 	else if(recStack[*i])
			 	 	return true;
				 	
			 }
			
		}
		
		recStack[v] = false;
		return false;
	}
	
	
	bool isCyclic(){
		bool *visited = new bool[V];
		bool *recStack = new bool[V];
		
		for(int i=0;i<V;i++)
			{
				visited[i] = false;
				recStack[i] = false;
			}
		
		for(int i=0;i<V;i++)
			{
				if(isCyclicUtil(i,visited,recStack))
					return true;
			}
		
		return false;	
	}
	
	
	
	
};


int main()
{
	DirectedCycle g(4);
	g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    
    
    if(g.isCyclic())
    	cout<<"graph contains cycle"<<endl;
    else
		cout<<"graph no cycle"<<endl;
	
	return 0;		


}

